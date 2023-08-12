#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct Subject {
    std::string name;
    int creditHours;
    double marksPercentage;
    char grade;
};

class CGPACalculator {
private:
    std::vector<Subject> subjects;

public:
    void addSubject(const std::string& name, int creditHours, double marksPercentage) {
        Subject subject = {name, creditHours, marksPercentage, ' '};
        subjects.push_back(subject);
    }

    char calculateGrade(double marksPercentage) {
        // Define your own criteria for calculating grades
        if (marksPercentage >= 90.0) {
            return 'A';
        } else if (marksPercentage >= 80.0) {
            return 'B';
        } else if (marksPercentage >= 70.0) {
            return 'C';
        } else if (marksPercentage >= 60.0) {
            return 'D';
        } else if (marksPercentage >= 50.0) {
            return 'E';
        } else {
            return 'F';
        }
    }

    std::string getClassification(double cgpa) {
        if (cgpa >= 3.5) {
            return "First Class";
        } else if (cgpa >= 2.5) {
            return "Second Class";
        } else {
            return "Third Class";
        }
    }

    double calculateCGPA() {
        double totalGradePoints = 0.0;
        int totalCreditHours = 0;

        for (const Subject& subject : subjects) {
            totalGradePoints += getGradePoint(subject.grade) * subject.creditHours;
            totalCreditHours += subject.creditHours;
        }

        if (totalCreditHours == 0) {
            return 0.0;
        }

        return totalGradePoints / totalCreditHours;
    }

    double getGradePoint(char grade) {
        // Define your own grade points mapping
        switch (grade) {
            case 'A': return 4.0;
            case 'B': return 3.0;
            case 'C': return 2.0;
            case 'D': return 1.0;
            case 'E': return 0.5;
            default: return 0.0;
        }
    }

    void calculateGrades() {
        for (Subject& subject : subjects) {
            subject.grade = calculateGrade(subject.marksPercentage);
        }
    }

    void displayTable() {
        std::cout << "-----------------------------------------------------------------------\n";
        std::cout << std::setw(20) << "Subject"
                  << std::setw(15) << "Credit Hours"
                  << std::setw(20) << "Marks Percentage"
                  << std::setw(10) << "Grade"
                  << std::endl;
        std::cout << "-----------------------------------------------------------------------\n";

        for (const Subject& subject : subjects) {
            std::cout << std::setw(20) << subject.name
                      << std::setw(15) << subject.creditHours
                      << std::setw(20) << subject.marksPercentage
                      << std::setw(10) << subject.grade
                      << std::endl;
        }

        std::cout << "-----------------------------------------------------------------------\n";
    }
};

int main() {
    CGPACalculator calculator;

    int numSubjects;
    std::cout << "Enter the number of subjects: ";
    std::cin >> numSubjects;

    for (int i = 0; i < numSubjects; ++i) {
        std::string name;
        int creditHours;

        std::cout << "Enter name of subject " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter credit hours for " << name << ": ";
        std::cin >> creditHours;

        double marksPercentage;
        std::cout << "Enter marks percentage for " << name << ": ";
        std::cin >> marksPercentage;

        calculator.addSubject(name, creditHours, marksPercentage);
    }

    calculator.calculateGrades();
    calculator.displayTable();

    double cgpa = calculator.calculateCGPA();
    std::string classification = calculator.getClassification(cgpa);

    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "CGPA: " << std::fixed << std::setprecision(2) << cgpa << std::endl;
    std::cout << "Classification: " << classification << std::endl;

    return 0;
}
