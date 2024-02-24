#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Patient {
public:
    string name;
    int age;
    string disease;
    string admissionDate;

    Patient(string n, int a, string d) : name(n), age(a), disease(d) {
        time_t now = time(0);
        admissionDate = ctime(&now);
    }
};

class Doctor {
public:
    string name;
    string specialization;

    Doctor(string n, string s) : name(n), specialization(s) {}
};

class Appointment {
public:
    Patient patient;
    Doctor doctor;
    string appointmentDate;

    Appointment(Patient p, Doctor d) : patient(p), doctor(d) {
        time_t now = time(0);
        appointmentDate = ctime(&now);
    }
};

class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    void admitPatient() {
        string name, disease;
        int age;

        cout << "Enter patient name: ";
        getline(cin, name);

        cout << "Enter patient age: ";
        cin >> age;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter patient disease: ";
        getline(cin, disease);

        patients.push_back(Patient(name, age, disease));

        cout << "------Patient admitted successfully!------" << endl;
    }

    void displayPatients() {
        if (patients.empty()) {
            cout << "No patients in the hospital." << endl;
        } else {
            cout << "Patients in the hospital:" << endl;
            for (const auto& patient : patients) {
                cout << "Name: "<<"|" << patient.name <<"| "<< "Age:"<<"|"  << patient.age<<"|" << " Disease:" <<"|" << patient.disease<<"|"
                     << ", Admission Date: " <<"|"<< patient.admissionDate<<"|";
            }
        }
    }

    void addDoctor() {
        string name, specialization;

        cout << "Enter doctor name: ";
        getline(cin, name);

        cout << "Enter doctor specialization: ";
        getline(cin, specialization);

        doctors.push_back(Doctor(name, specialization));

        cout << "Doctor added successfully!" << endl;
    }

    void displayDoctors() {
        if (doctors.empty()) {
            cout << "No doctors in the hospital." << endl;
        } else {
            cout << "Doctors in the hospital:" << endl;
            for (const auto& doctor : doctors) {
                cout << "Name: " << doctor.name << ", Specialization: " << doctor.specialization << endl;
            }
        }
    }

    void scheduleAppointment() {
        if (patients.empty() || doctors.empty()) {
            cout << "Cannot schedule appointment. No patients or doctors available." << endl;
            return;
        }

        int patientIndex, doctorIndex;

        cout << "Select a patient for the appointment:" << endl;
        displayPatients();
        cout << "Enter the index of the patient: ";
        cin >> patientIndex;

        cout << "Select a doctor for the appointment:" << endl;
        displayDoctors();
        cout << "Enter the index of the doctor: ";
        cin >> doctorIndex;

        appointments.push_back(Appointment(patients[patientIndex], doctors[doctorIndex]));

        cout << "Appointment scheduled successfully!" << endl;
    }

    void displayAppointments() {
        if (appointments.empty()) {
            cout << "No appointments scheduled." << endl;
        } else {
            cout << "Scheduled appointments:" << endl;
            for (const auto& appointment : appointments) {
                cout << "Patient: " << appointment.patient.name << ", Doctor: " << appointment.doctor.name
                     << ", Appointment Date: " << appointment.appointmentDate;
            }
        }
    }
};

int main() {
    Hospital hospital;
    int choice;

    do {
        cout << "\n AM-Hospital Management \n\n";
        cout << "1. Admit Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. Display Doctors\n";
        cout << "5. Schedule Appointment\n";
        cout << "6. Display Appointments\n";
        cout << "7. Exit\n";
        cout<<"==========================================="<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // Ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                hospital.admitPatient();
                break;
            case 2:
                hospital.displayPatients();
                break;
            case 3:
                hospital.addDoctor();
                break;
            case 4:
                hospital.displayDoctors();
                break;
            case 5:
                hospital.scheduleAppointment();
                break;
            case 6:
                hospital.displayAppointments();
                break;
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
