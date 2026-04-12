#include<iostream>
using namespace std;

int main(){
    int check_answer,my_answer;
    cin >> check_answer >> my_answer;
    if(my_answer >= check_answer) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }    
    return 0;
}