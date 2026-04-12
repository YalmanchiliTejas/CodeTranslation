#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int n;
    cin>>n;
    string s="yes";
    vector<int>a(500000);
    vector<int>b(500000);
    vector<int>c(500000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[i+1]++;
        b[i+a[i]/10+1]--;
    }
    for(int i=0;i<n-1;i++){
        b[i+1]+=b[i];
    }
    for(int i=0;i<n;i++){
        c[i+1]++;
        c[i+a[n-1-i]/10+1]--;
    }
    for(int i=0;i<n-1;i++){
        c[i+1]+=c[i];
    }
    b[0]++;
    c[0]++;
    for(int i=0;i<n;i++){
        if(b[i]==0||c[i]==0){
            s="no";
        }
    }
    cout<<s<<endl;

    return 0;
}
