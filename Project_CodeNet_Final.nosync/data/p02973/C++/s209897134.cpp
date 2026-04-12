#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long int> b(2);
    b.at(0)=1000000001;
    b.at(1)=a[0]-1;
    int x;
    for(int i=0;i<n;i++){
        x=b.size();
        if(b.at(x-1)>=a[i]){
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