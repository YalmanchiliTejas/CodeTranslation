#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007


int main(){
    int h,w;
    cin>>h>>w;

    vector<string> t(h);

    for(int i=0;i<h;i++)cin>>t.at(i);

    vector<int> H(h,0);
    vector<int> W(w,0);

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(t.at(i).at(j)=='#'){
                H.at(i) = 1;
                W.at(j) = 1;
            }
        }
    }

    int d;
    for(int i=0;i<h;i++){
        d=0;
        for(int j=0;j<w;j++){
            if(H.at(i)==1&&W.at(j)==1){
                cout<<t.at(i).at(j);
                d=1;
            }
        }
        if(d!=1)continue;
        cout<<endl;
    }

}

