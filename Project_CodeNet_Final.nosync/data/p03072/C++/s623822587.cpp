#include <bits/stdc++.h>
using namespace std;

int f(int i,vector<int> a){
    bool p=true;
    for(int k=0;k<i;k++){
        if(a[i]>=a[k])
            continue;
        else{
            p=false;
            break;
        }        
    }
    if(p)
        return 1;
    else
        return 0;
}

int main(){
    int n,count=1;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++)
        cin >> h[i];
    for(int i=1;i<n;i++){
        count+=f(i,h);
    }
    cout << count;
}