#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    string s,a;
    int n,k;
    cin>>n>>s>>k;
    a=s;
    string x;
    x=s[k-1];
    for(int i=0;i<n;i++){
        string ss;
        ss=s[i];
        if(ss!=x){
            a[i]='*';
        }
        cout<<a[i];
    }
    cout<<endl;
    
    return 0;
}

