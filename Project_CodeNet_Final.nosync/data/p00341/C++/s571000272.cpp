#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a(12);
    for (int i = 0; i < 12; ++i) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j < 4; ++j) {
            if(a[4*i+j]!=a[4*i+j-1]){
                cout<<"no"<<endl;
                return 0;
            }
        }
    }
    cout<<"yes"<<endl;

    return 0;
}
