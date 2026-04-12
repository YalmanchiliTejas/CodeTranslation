#include <iostream>

using namespace std;

int main() {
    int number_of_test_case, number_of_correct_answer;

    cin >> number_of_test_case >> number_of_correct_answer;

    if(number_of_test_case == number_of_correct_answer) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}