#include <bits/stdc++.h>
using  namespace std;
int main(){
    long long n, t, check = 100;
    string s, ans="";
    cin >> n;
    long long S[n][26];
    for(int i=0;i<n;i++){
      for(int j=0;j<26;j++){
        S[i][j] = 0;
      }
    }
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<s.length();j++){
            S[i][int(s[j])-97]++;
        }
    }
    for(int i=0;i<26;i++){
        check = 100;
        for(int j=0;j<n;j++){
            check = min(check, S[j][i]);
        }
      	for(int k=0;k<check;k++){
           ans += char(i+97);
        }    
    }
    
    cout << ans << endl;
    return 0;
 
}
