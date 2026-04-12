#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin);
    int n, k;
    string s;

    cin>>n;
    cin>>s;
    cin>>k;

    k--;
    char c = s[k];

    for (int i=0;i<n;++i){
        if (s[i]!=c) printf ("*");
        else cout<<s[i];
    }
    cout<<endl;

    return 0;
}