#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int c[26];
    for (int i=0;i<26;i++)
        c[i]=1e9;
    int n;cin>>n;
    for (int i=0;i<n;i++) {
        string s;cin>>s;
        int cc[26]{};
        for (auto c:s)
            cc[c-'a']++;
        for (int i=0;i<26;i++)
            c[i]=min(c[i],cc[i]);
    }
    for (int i=0;i<26;i++)
        for (int j=0;j<c[i];j++)
            putchar('a'+i);
    cout<<endl;
    return 0;
}