#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ALL(A) A.begin(),A.end()
const long long mod=1000000007;
int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    char rep=s[k-1];
    for(int i=0;i<n;i++)
    {
        if(s[i]!=rep)
        s[i]='*';
    }
    cout<<s<<endl;
    return 0;
}