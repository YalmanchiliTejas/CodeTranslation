#include <bits/stdc++.h>
using namespace std;

long long int d[3*1000000 + 2];

int main() {

    int n;

    cin >> n;

    for(int i=0;i<n;i++){
       cin >> d[i];
    }

    bool flag = false;

    int npos = 0;

    while(!flag){

        long long int mj = 0;
        int maxpos=0;

        for(int i=npos;i<=npos+d[npos]/10;i++){
            if(i == n-1){
                flag = true;
                break;
            }
            if(i==npos) continue;
            if(mj/10 + maxpos <= i + d[i]/10){
                mj = d[i];
                maxpos = i;
            }
        }
        if(mj<10){
            break;
        }
        npos = maxpos;

    }

    if (!flag) {
        cout << "no" << endl;
        return 0;
    }

    reverse(d,d+n);


    flag = false;

    npos = 0;

    while(!flag){

        long long int mj = 0;
        int maxpos=0;

        for(int i=npos;i<=npos+d[npos]/10;i++){
            if(i == n-1){
                flag = true;
                break;
            }
            if(i==npos) continue;
            if(mj/10 + maxpos <= i + d[i]/10){
                mj = d[i];
                maxpos = i;
            }
            //mj = max(mj,d[i]);
        }
        if(mj<10){
            break;
        }
        npos = maxpos;

    }

    if (!flag) {
        cout << "no" << endl;
    }
    else{
        cout << "yes" << endl;
    }


    return 0;
}