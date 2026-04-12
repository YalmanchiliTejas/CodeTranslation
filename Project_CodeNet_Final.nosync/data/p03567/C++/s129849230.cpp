#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]=='A' && s[i+1]=='C'){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
