#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b(2);
    b.at(0)=1000000001;
    b.at(1)=-1;
    for(int i=0;i<n;i++){
        if(b.at(b.size()-1)>=a[i]){
            b.push_back(a[i]);
            continue;
        }
        for(int j=1;j<b.size();j++){
            if(b.at(j)<a[i]){
                b.at(j)=a[i];
                break;
            }
        }
    }
    cout<<b.size()-1<<endl;
}