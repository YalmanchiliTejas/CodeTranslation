#include <iostream>
using namespace std;

int main(){
    int n, k;
    char s[15], tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cin >> k;
    tmp = s[k-1];
    for(int i = 0; i < n; i++){
        if(s[i] != tmp){
            s[i] = '*';
        }
        cout << s[i];
    }
    cout << endl;
}
