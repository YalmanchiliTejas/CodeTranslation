#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    char s[20];
    cin >> n;
    for(int j=0; j<n; j++){
        cin >> s[j];
    }

    cin >> k;

    for(int i=0; i<n; i++){
        if(s[i] == s[k-1]){
            cout << s[i];
        }
        else{
            cout << "*" ;
        }
    }
    cout << endl;
}

