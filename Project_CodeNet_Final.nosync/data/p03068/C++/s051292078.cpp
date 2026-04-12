#include <iostream>
#include <string>
using namespace std;
int main(void){

    int n, k;
    string s;
    
    cin >> n >> s >> k;
    
    string temp = s.substr(k-1, 1);

    string result;
    for(int i=0; i<s.size(); i++) {
        if(s.substr(i,1) != temp) {
            result += "*";
        }
        else result += s.substr(i,1);
    }

    cout << result << endl;

    return 0;
}
