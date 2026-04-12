#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n;
    char s[n], ans[n];
    for(int i = 0 ; i < n; i++) cin >> s[i];
    cin >> k;
    
    for(int i = 0; i < n ; i++){
        if(s[i] != s[k -1]){
            ans[i] = '*';
        } else {
            ans[i] = s[i];            
        }
    }
    for(int i = 0; i < n ; i++) cout << ans[i];
    cout << endl;

}