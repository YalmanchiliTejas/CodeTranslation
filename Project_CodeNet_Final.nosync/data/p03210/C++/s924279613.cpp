#include <iostream>
#include <string>

using namespace std;

int main(){
    int age;
    string ans = "NO";
    cin >> age;
    if (age == 3 || age == 5 || age == 7) {
        ans="YES";
    }
    cout << ans;
}