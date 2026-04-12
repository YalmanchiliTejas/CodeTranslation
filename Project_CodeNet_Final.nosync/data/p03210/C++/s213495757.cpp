#include <iostream>
#include <string>
using namespace std;

string solve(int n);

int main(){
    int age = 0;
    cin >> age;
    
    cout << solve(age) << endl;
    
    return 0;
}

string solve(int n){
     if(n == 7 || n == 5 || n == 3){
        return "YES";
    }else{
        return "NO";
    }
}