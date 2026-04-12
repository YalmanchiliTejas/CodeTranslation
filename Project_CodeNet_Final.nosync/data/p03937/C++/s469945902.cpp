#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int h,w; cin>>h>>w;
    string s;
    int sta = -1;
    for (int i=0; i<h; i++){
        cin >> s;
        for (int j=0; j<w; j++){
            if (s[j]=='#'){
                if (i+j-1==sta) sta++;
                else{
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Possible" << endl;
}