#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int a[100][30];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            a[i][s[j]-'a']++;
        }
    }
    string al="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<26;i++){
        int t=1000;
        for(int j=0;j<n;j++){
            t=min(t,a[j][i]);
        }
        for(int k=0;k<t;k++){
            cout<<al[i];
        }
    }
    cout<<endl;
    return 0;
}
