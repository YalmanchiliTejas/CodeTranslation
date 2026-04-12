//78B
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
int main(void){
    int d, width, space;
    int cnt =0;
    cin >> d >> width >>space;
    while(true){
        d-=(width + space);
        //cout << d<< endl;
        if(d>=space){
            cnt+=1;
        }else{
            break;
        }
        
    }
    cout << cnt << endl;
}