#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    char s[n];cin >> s;
    int k;cin >> k;
    char c = s[k-1];
    for(int i=0;i<n;i++){
        if(s[i] == c){

        }
        else{
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}