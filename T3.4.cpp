#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Define a class for Student
class Student {
public:
    // Constructor
    Student(string name, double grade)
        : name_(move(name)), grade_(grade) {}

    // Getter functions
    string getName() const {
        return name_;
    }

    double getGrade() const {
        return grade_;
    }

private:
    string name_;
    double grade_;
};

// Function to find students with the highest grade
vector<Student> findStudentsWithHighestGrade(const vector<Student>& students) {
    // Find the maximum grade
    auto maxGrade = std::max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getGrade() < b.getGrade();
        });

    // Find all students with the maximum grade
    vector<Student> highestGradeStudents;
    double highestGradeValue = maxGrade->getGrade();

    copy_if(students.begin(), students.end(), back_inserter(highestGradeStudents),
        [highestGradeValue](const Student& student) {
            return student.getGrade() == highestGradeValue;
        });

    return highestGradeStudents;
}

int main() {
    // Create a vector of Student objects
    vector<Student> students = {
        {"Ana", 90.5},
        {"Andi", 85.0},
        {"George", 90.5},
        {"Vali", 88.0},
        // Add more students as needed
    };

    // Find students with the highest grade
    vector<Student> highestGradeStudents = findStudentsWithHighestGrade(students);

    // Display students with the highest grade
    if (!highestGradeStudents.empty()) {
        cout << "Students with the highest grade:\n";
        for (const auto& student : highestGradeStudents) {
            cout << "Name: " << student.getName() << ", Grade: " << student.getGrade() << "\n";
        }
    }
    else {
        cout << "No students found.\n";
    }

    return 0;
}
