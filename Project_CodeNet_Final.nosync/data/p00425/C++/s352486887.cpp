
#include <iostream>
#include <cstdio>
#include <cmath>

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)


using namespace std;

int main(void){
    int n;
    int t, f, r;
    int tt , ff , rr;
    int s;
    string str;
    while (cin>>n && n){
        t=1,f=2,r=3;
        s=1;
        REP(i,n){
            cin >> str;
            if (str=="North"){
                tt=f;
                ff=7-t;
                t=tt;
                f=ff;
            }else if (str=="East"){
                tt=7-r;
                rr=t;
                t=tt;
                r=rr;
            }else if (str=="South"){
                tt=7-f;
                ff=t;
                t=tt;
                f=ff;
            }else if (str=="West"){
                tt=r;
                rr=7-t;
                t=tt;
                r=rr;
            }else if (str=="Right"){
                ff=r;
                rr=7-f;
                f=ff;
                r=rr;
            }else if (str=="Left"){
                ff=7-r;
                rr=f;
                f=ff;
                r=rr;
            }
            s+=t;
//            cout << s << endl;
        }
        cout << s << endl;
    }
    
    return 0;
}