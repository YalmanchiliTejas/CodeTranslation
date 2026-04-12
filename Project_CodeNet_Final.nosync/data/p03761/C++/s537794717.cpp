#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s="abcdefghijklmnopqrstuvwxyz";
    vector<string>a(100);
    vector<int>b(26);
    vector<int>c(26);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<26;i++){
        b[i]=count(a[0].begin(), a[0].end(), s[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++){
            c[j]=count(a[i].begin(), a[i].end(), s[j]);
        }
        for(int j=0;j<26;j++){
            if(c[j]<b[j]){
                b[j]=c[j];
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;b[i]>j;j++){
            cout<<s[i]<<flush;
        }
    }
    cout<<endl;
    
    return 0;
}
