#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//                                          STRUCT STRUCTURE DECLARATION

struct Patient {
    int patient_id;
    string name;
    int age;
    string contact_no;
    string medical_history;
    int doctor_id;
    string appointment;
    string medical_record;
    double total_cost;    
    Patient* next;
};

struct Doctor {
    int doctor_id;
    string name;
    string contact_no;
    string specialist;
    Doctor* next;
};


// ************************************************************************************************************************************************** //
//                                                     PATIENTS RECORD AREA

// Function to search for a doctor by ID to assigned him to the patient
Doctor* search_doctor_by_Id(Doctor** head_ref, int doctor_id) {
    Doctor* curr = *head_ref;
    while (curr != NULL) {
        if (curr->doctor_id == doctor_id) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// Function to insert a patient
void insertPatient(Patient** head_ref, Doctor** doctor_head_ref) {
    Patient* ptr = new Patient;  
    cout << "Enter the patient ID : ";
    cin >> ptr->patient_id;
    cout << "Enter the name : ";
    cin.ignore();
    getline(cin , ptr->name);
    cout << "Enter the age : ";
    cin >> ptr->age;
    cout << "Enter the contact number : ";
    cin >> ptr->contact_no;
    cout << "Enter the medical history : ";
    cin.ignore();
    getline(cin , ptr->medical_history);
    int doctor_id;
    cout << "Enter the doctor ID to assign: ";
    cin >> doctor_id;
    Doctor* assign_doctor = search_doctor_by_Id(doctor_head_ref, doctor_id);
    if (assign_doctor != NULL) {
        cout << "Doctor " << assign_doctor->name << " assign to patient " << ptr->name << endl;
        ptr->doctor_id = doctor_id;
    } else {
        cout << "Doctor with ID " << doctor_id << " not found. Cannot assign to patient." << endl;
        ptr->doctor_id = -1; // its show that there is no doctor assigned to the patient
    }
    ptr->appointment = "No appointment"; // show that there is no appointment of the patient to the doctor
    ptr->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = ptr;
    } 
    else {
        Patient* curr = *head_ref;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = ptr;
    }
}

// Function to search for a patient
void searchPatient(Patient** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Patient* curr = *head_ref;
    int tosearch;
    cout << "Enter the patient ID that you want to search: ";
    cin >> tosearch;
    while (curr != NULL) {
        if (curr->patient_id == tosearch) {
            cout << "Patient ID: " << curr->patient_id << endl;
            cout << "Name: " << curr->name << endl;
            cout << "Age: " << curr->age << endl;
            cout << "Contact Number: " << curr->contact_no << endl;
            cout << "Medical history: " << curr->medical_history << endl;
            cout << "Assigned Doctor ID: " << curr->doctor_id << endl;
            cout << "Appointment: " << curr->appointment << endl;
            cout << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "The patient record has not been found in the list" << endl;
}

// Function to print the required patient
void printPatients(Patient** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    int patientid;
    cout << "enter the id of the patient that you want to print the detail: ";
    cin >> patientid;
    Patient* curr = *head_ref;
    while (curr != NULL) {
        if(curr->patient_id==patientid){
            cout << "Patient ID: " << curr->patient_id << endl;
            cout << "Name: " << curr->name << endl;
            cout << "Age: " << curr->age << endl;
            cout << "Contact Number: " << curr->contact_no << endl;
            cout << "Medical history: " << curr->medical_history << endl;
            cout << "Assigned Doctor ID: " << curr->doctor_id << endl;
            cout << "Appointment: " << curr->appointment << endl;
            cout << endl;
        }    
        curr = curr->next;
    }
}

// Function to delete a patient
void deletePatient(Patient** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Patient* curr = *head_ref;
    Patient* prev = NULL;
    int todel;
    cout << "Enter the patient ID that you want to delete: ";
    cin >> todel;
    if (curr->patient_id == todel) {
        *head_ref = curr->next;
        delete curr;
        cout << "The patient record has been deleted" << endl;
        return;
    }
    while (curr != NULL && curr->patient_id != todel) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "The patient record has not been found in the list" << endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
    cout << "The patient record has been deleted" << endl;
}

// Function to update a patient
void updatePatient(Patient** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Patient* curr = *head_ref;
    int tosearch;
    cout << "Enter the patient ID that you want to update: ";
    cin >> tosearch;
    cin.ignore();  // Ignore the newline character left in the buffer by cin
    while (curr != NULL) {
        if (curr->patient_id == tosearch) {
            string field;
            cout << "Enter the field you want to update (name/contact/age/medical/doctor): ";
            cin >> field;
            cin.ignore();  // Ignore the newline character left in the buffer by cin
            if (field == "name") {
                cout << "Enter the new name: ";
                getline(cin, curr->name);  // allow every line as input including space
            } 
            else if (field == "contact") {
                cout << "Enter the new contact number: ";
                getline(cin, curr->contact_no);
            } 
            else if (field == "age") {
                cout << "Enter the new age: ";
                cin >> curr->age;
                cin.ignore();  // Ignore the newline character left in the buffer by cin
            } 
            else if (field == "medical") {
                cout << "Enter the new medical history: ";
                getline(cin, curr->medical_history);
            } 
            else if (field == "doctor") {
                cout << "Enter the doctor id: ";
                cin >> curr->doctor_id;
                cin.ignore();  // Ignore the newline character left in the buffer by cin
            } 
            else {
                cout << "Wrong field" << endl;
            }       
            cout << "The patient record has been updated" << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "The patient record has not been found in the list" << endl;
}

// Function to count number of patients
int countPatients(Patient* head_ref) {
    if (head_ref == NULL) {
        return 0;
    }
    int count = 0;
    Patient* curr = head_ref;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}


// **************************************************************************************************************************************************** //
//                                           DOCTOR RECORD AREA

// Function to insert a doctor
void insertDoctor(Doctor** head_ref) {
    Doctor* ptr = new Doctor;  
    cout << "Enter the doctor ID : ";
    cin >> ptr->doctor_id;
    cout << "Enter the doctor name : ";
    cin.ignore();
    getline(cin , ptr->name);
    cout << "Enter the doctor contact number : ";
    cin >>  ptr->contact_no;
    cout << "Enter the doctor specialist : ";
    cin.ignore();
    getline(cin , ptr->specialist);
    ptr->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = ptr;
    } 
    else {
        Doctor* curr = *head_ref;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = ptr;
    }
}

// Function to search for a doctor
void searchDoctor(Doctor** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Doctor* curr = *head_ref;
    int tosearch;
    cout << "Enter the doctor ID that you want to search: ";
    cin >> tosearch;
    while (curr != NULL) {
        if (curr->doctor_id == tosearch) {
            cout << "Doctor ID: " << curr->doctor_id << endl;
            cout << "Name: " << curr->name << endl;
            cout << "Contact Number: " << curr->contact_no << endl;
            cout << "Specialist: " << curr->specialist << endl;
            cout << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "The doctor record has not been found in the list" << endl;
}

// Function to print required doctors
void printDoctors(Doctor** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Doctor* curr = *head_ref;
    int doctorid;
    cout << "enter the id of the doctor that you want the detail: ";
    cin >> doctorid;
    while (curr != NULL) {
        if(curr->doctor_id==doctorid){
            cout << "Doctor ID: " << curr->doctor_id << endl;
            cout << "Name: " << curr->name << endl;
            cout << "Contact Number: " << curr->contact_no << endl;
            cout << "Specialist: " << curr->specialist << endl;
            cout << endl;
        }
        curr = curr->next;
    }
}

// Function to delete a doctor
void deleteDoctor(Doctor** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Doctor* curr = *head_ref;
    Doctor* prev = NULL;
    int todel;
    cout << "Enter the doctor ID that you want to delete: ";
    cin >> todel;
    if (curr->doctor_id == todel) {
        *head_ref = curr->next;
        delete curr;
        cout << "The doctor record has been deleted" << endl;
        return;
    }
    while (curr != NULL && curr->doctor_id != todel) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "The doctor record has not been found in the list" << endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
    cout << "The doctor record has been deleted" << endl;
}

// Function to update a doctor
void updateDoctor(Doctor** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Doctor* curr = *head_ref;
    int tosearch;
    cout << "Enter the doctor ID that you want to update: ";
    cin >> tosearch;
    cin.ignore();  
    while (curr != NULL) {
        if (curr->doctor_id == tosearch) {
            cout << "Enter the field you want to update (name/contact/specialist): ";
            string field;
            cin >> field;
            cin.ignore();         
            if (field == "name") {
                cout << "Enter the new name: ";
                getline(cin, curr->name);
            } 
            else if (field == "contact") {
                cout << "Enter the new contact number: ";
                getline(cin, curr->contact_no);
            } 
            else if (field == "specialist") {
                cout << "Enter the new specialist: ";
                getline(cin, curr->specialist);
            } 
            else {
                cout << "Invalid field" << endl;
            }
            cout << "The doctor record has been updated" << endl;
            return;
        }
        curr = curr->next;
    }   
    cout << "The doctor record has not been found in the list" << endl;
}

// Function to count number of doctors
int countDoctors(Doctor* head_ref) {
    if (head_ref == NULL) {
        return 0;
    }
    int count = 0;
    Doctor* curr = head_ref;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}


// ************************************************************************************************************************************************** //
//                                                  APPOINTMENT AREA

// Function to book an appointment
void bookAppointment(Patient** patient_head_ref, Doctor** doctor_head_ref) {
    if (*patient_head_ref == NULL) {
        cout << "The patient list is empty" << endl;
        return;
    }
    int patient_id;
    cout << "Enter the patient ID to book an appointment: ";
    cin >> patient_id;
    
    Patient* patient = *patient_head_ref;
    while (patient != NULL) {
        if (patient->patient_id == patient_id) {
            int doctor_id;
            cout << "Enter the doctor ID for the appointment: ";
            cin >> doctor_id;
            
            Doctor* doctor = search_doctor_by_Id(doctor_head_ref, doctor_id);
            if (doctor != NULL) {
                cout << "Enter the appointment details (date and time): ";
                cin.ignore();
                getline(cin, patient->appointment);
                patient->doctor_id = doctor_id;
                cout << "Appointment booked for patient " << patient->name << " with doctor " << doctor->name << endl;
            } else {
                cout << "Doctor with ID " << doctor_id << " not found. Appointment cannot be booked." << endl;
            }
            return;
        }
        patient = patient->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}

// Function to cancel an appointment
void cancelAppointment(Patient** patient_head_ref) {
    if (*patient_head_ref == NULL) {
        cout << "The patient list is empty" << endl;
        return;
    }
    int patient_id;
    cout << "Enter the patient ID to cancel the appointment: ";
    cin >> patient_id;    
    Patient* patient = *patient_head_ref;
    while (patient != NULL) {
        if (patient->patient_id == patient_id) {
            patient->appointment = "No appointment";
            patient->doctor_id = -1;
            cout << "Appointment canceled for patient " << patient->name << endl;
            return;
        }
        patient = patient->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}

// Function to view an appointment
void viewAppointment(Patient** patient_head_ref) {
    if (*patient_head_ref == NULL) {
        cout << "The patient list is empty" << endl;
        return;
    }
    int patient_id;
    cout << "Enter the patient ID to view the appointment: ";
    cin >> patient_id;    
    Patient* patient = *patient_head_ref;
    while (patient != NULL) {
        if (patient->patient_id == patient_id) {
            cout << "Patient ID: " << patient->patient_id << endl;
            cout << "Name: " << patient->name << endl;
            cout << "Appointment: " << patient->appointment << endl;
            cout << "Assigned Doctor ID: " << patient->doctor_id << endl;
            return;
        }
        patient = patient->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}


// ************************************************************************************************************************************************** //
//                                                MEDICAL RECORD AREA NEW ONE

// Function to add medical record
void addMedicalRecord(Patient** head_ref) {
    if (*head_ref == NULL) {
        cout << "The patient list is empty" << endl;
        return;
    }
    int patient_id;
    cout << "Enter the patient ID to add medical record: ";
    cin >> patient_id;    
    Patient* patient = *head_ref;
    while (patient != NULL) {
        if (patient->patient_id == patient_id) {
            cout << "Enter the medical record: ";
            cin.ignore();
            getline(cin, patient->medical_record);
            cout << "Medical record added for patient " << patient->name << endl;
            return;
        }
        patient = patient->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}

// Function to update medical record
void updateMedicalRecord(Patient** head_ref) {
    if (*head_ref == NULL) {
        cout << "The patient list is empty" << endl;
        return;
    }
    int patient_id;
    cout << "Enter the patient ID to update medical record: ";
    cin >> patient_id;    
    Patient* patient = *head_ref;
    while (patient != NULL) {
        if (patient->patient_id == patient_id) {
            cout << "Enter the updated medical record: ";
            cin.ignore();
            getline(cin, patient->medical_record);
            cout << "Medical record updated for patient " << patient->name << endl;
            return;
        }
        patient = patient->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}

// Function to view medical record
void viewMedicalRecord(Patient** head_ref) {
    if (*head_ref == NULL) {
        cout << "The patient list is empty" << endl;
        return;
    }
    int patient_id;
    cout << "Enter the patient ID to view the medical record: ";
    cin >> patient_id;    
    Patient* patient = *head_ref;
    while (patient != NULL) {
        if (patient->patient_id == patient_id) {
            cout << "Patient ID: " << patient->patient_id << endl;
            cout << "Name: " << patient->name << endl;
            cout << "Medical Record: " << patient->medical_record << endl;
            return;
        }
        patient = patient->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}


// ************************************************************************************************************************************************ //
//                                          BILLING AREA FOR PATIENT

// Function to calculate the bill for a patient
double getBill(Patient** head_ref) {
    Patient* curr = *head_ref;
    double bill = 0.0;
    if (curr->medical_record == "heart") {
        bill += 200.0;
    } else if (curr->medical_record == "eye") {
        bill += 100.0;
    } else if (curr->medical_record == "lunge") {
        bill += 300.0;
    } else if (curr->medical_record == "fracture") {
        bill += 50.0;
    } else if (curr->medical_record == "operation") {
        bill += 500.0;
    } else if (curr->medical_record == "ope") {
        bill += 20.0;
    }
    return bill;
}

// Function to process patient bill
void processBill(Patient** head_ref) {
    int patient_id;
    cout << "Enter the ID of the patient for whom you want to process the bill: ";
    cin >> patient_id;
    Patient* curr = *head_ref;
    while (curr != NULL) {
        if (curr->patient_id == patient_id) {
            curr->total_cost = getBill(head_ref);
            cout << "Bill processed for patient " << curr->name << " with ID " << curr->patient_id << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}

// Function to view billing information
void viewBill(Patient** head_ref) {
    int patient_id;
    cout << "Enter the patient ID for whom you want the bill: ";
    cin >> patient_id;
    Patient* curr = *head_ref;
    while (curr != NULL) {
        if (curr->patient_id == patient_id) {
            cout << "Patient ID: " << curr->patient_id << endl;
            cout << "Total Cost: $" << fixed << setprecision(2) << curr->total_cost << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Patient with ID " << patient_id << " not found." << endl;
}


// ************************************************************************************************************************************************ //
//                                                    GENEARTE REPORT AREA

// function to genearate report of thepatient which include all the info
void generateReport(Patient* patient_head, Doctor* doctor_head) {   
    if (patient_head == NULL) {
        cout << "No patients found." << endl;
        return;
    }
    Patient* curr_patient = patient_head;
    while (curr_patient != NULL) {
        cout << "Patient ID: " << curr_patient->patient_id << endl;
        cout << "Name: " << curr_patient->name << endl;
        cout << "Age: " << curr_patient->age << endl;
        cout << "Contact Number: " << curr_patient->contact_no << endl;
        cout << "Medical History: " << curr_patient->medical_history << endl;
        Doctor* assignedDoctor = search_doctor_by_Id(&doctor_head, curr_patient->doctor_id);
        if (assignedDoctor != NULL) {
            cout << "Assigned Doctor: " << assignedDoctor->name << endl;
            cout << "Doctor's Contact Number: " << assignedDoctor->contact_no << endl;
            cout << "Specialist: " << assignedDoctor->specialist << endl;
        } else {
            cout << "No assigned doctor." << endl;
        }
        cout << "Appointment: " << curr_patient->appointment << endl;
        cout << "Medical Record: " << curr_patient->medical_record << endl;
        cout << "Billing Information: $" << fixed << setprecision(2) << curr_patient->total_cost << endl;
        curr_patient = curr_patient->next;
    }
}


// *************************************************************************************************************************************************** //
//                                  PRINT FUNCTIONALITY AREA

// print function name 
void print_function_name(){
    cout << endl;
    cout << "Enter 0 to exit" << endl;
    cout << "Enter 1 to insert patient" << endl;
    cout << "Enter 2 to search patient" << endl;
    cout << "Enter 3 to print patients" << endl;
    cout << "Enter 4 to delete a patient record" << endl;
    cout << "Enter 5 to update a patient record" << endl;
    cout << "Enter 6 to get the total number of patients" << endl;
    cout << "Enter 7 to insert doctor" << endl;
    cout << "Enter 8 to search doctor" << endl;
    cout << "Enter 9 to print doctors" << endl;
    cout << "Enter 10 to delete a doctor record" << endl;
    cout << "Enter 11 to update a doctor record" << endl;
    cout << "Enter 12 to get the total number of doctors" << endl;
    cout << "Enter 13 to book an appointment" << endl;
    cout << "Enter 14 to cancel an appointment" << endl;
    cout << "Enter 15 to view an appointment" << endl;
    cout << "Enter 16 to add medical record" << endl;
    cout << "Enter 17 to update medical record" << endl;
    cout << "Enter 18 to print medical record" << endl;
    cout << "Enter 19 to process bill" << endl;
    cout << "Enter 20 to view bill" << endl;
    cout << "Enter 21 to geneate report" << endl;
    cout << endl;
}


// *********************************************************************************************************************************************** //
//                                      MAIN FUNCTION AREA

// main function
int main() {
    Patient* patient_head = NULL;
    Doctor* doctor_head = NULL;
    int select;
    print_function_name();
    cout << "enter your choice: ";
    cin >> select;
    while (select != 0) {
        if (select == 1) { insertPatient(&patient_head, &doctor_head); }
        if (select == 2) { searchPatient(&patient_head); }
        if (select == 3) { printPatients(&patient_head); }
        if (select == 4) { deletePatient(&patient_head); }
        if (select == 5) { updatePatient(&patient_head); }
        if (select == 6) { cout << "Total number of patients: " << countPatients(patient_head) << endl; }
        if (select == 7) { insertDoctor(&doctor_head); }
        if (select == 8) { searchDoctor(&doctor_head); }
        if (select == 9) { printDoctors(&doctor_head); }
        if (select == 10) { deleteDoctor(&doctor_head); }
        if (select == 11) { updateDoctor(&doctor_head); }
        if (select == 12) { cout << "Total number of doctors: " << countDoctors(doctor_head) << endl; }
        if (select == 13) { bookAppointment(&patient_head, &doctor_head); }
        if (select == 14) { cancelAppointment(&patient_head); }
        if (select == 15) { viewAppointment(&patient_head); }
        if (select == 16) { addMedicalRecord(&patient_head); }
        if (select == 17) { updateMedicalRecord(&patient_head); }
        if (select == 18) { viewMedicalRecord(&patient_head); }
        if (select == 19) { processBill(&patient_head); }
        if (select == 20) { viewBill(&patient_head); }
        if(select == 21)  { generateReport(patient_head, doctor_head);}
        print_function_name();
        cout << "\nEnter your next choice: ";
        cin >> select;
    }
    cout << endl;
    cout << endl;
    cout << "\t\t***** Thanks for using the program made by ABDUL MOIZ 2024 *****\t\t" << endl;
    cout << endl;
    cout << endl;
    return 0;
}
