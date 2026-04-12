#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string n , m;
    cin >> n >> m;
    int n1 = stoi(n);
    int m1 = stoi(m);
    if (n1 == 0){
        cout << "No" << endl;
    }
    int result = m1 / n1 ;
    if(result==1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
