#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    string s,s1,s2;
    scanf("%d",&n);
    cin>>s;
    scanf("%d",&k);
    s1+=s[k-1];
    for(int i=0; i<s.size(); i++) {
        if(s[i]!=s1[0]) {
            s2+="*";
            continue;
        }
        s2+=s[i];
    }
    cout<<s2<<endl;
    return 0;
}
