#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#define ll long long int
#define MOD 1000000007LL
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[30];
    for(int i=0;i<26;i++){
        a[i]=MOD;
    }
    for(int i=0;i<n;i++){
        int b[30]={};
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            int d=s[j]-'a';
            b[d]++;
        }
        for(int j=0;j<26;j++){
            a[j]=min(b[j],a[j]);
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<a[i];j++){
            char c=i+'a';
            cout<<c;
        }
    }
    cout<<endl;
}
