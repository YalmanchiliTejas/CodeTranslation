#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,sum=1;
    bool a;
    cin >> n;
    vector<int> h(n);
    cin >> h.at(0);
    for(int i=1;i<n;i++){
        a=true;
        cin >>h.at(i);
        for(int l=0;l<i;l++){
            if(h.at(i)<h.at(l)){
                a=false;
                break;
            }
        }
        if(a){
            sum++;
        }
    }
    cout << sum << endl;
}