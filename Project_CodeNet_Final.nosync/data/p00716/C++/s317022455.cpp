#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int m;
    cin >> m;
    for(int dat=0;dat<m;dat++){
        int init,nen,n;
        cin >> init >> nen >> n;
        int m = -1;
        for(int i=0;i<n;i++){
            int how,tesu;
            double rate;
            cin >> how >> rate >> tesu;
            int have = init;
            int soko = 0;
            for(int j=0;j<nen;j++){
                double r = have*rate;
                int rr = floor(r);
                if(how){
                    have += rr - tesu;
                }else{
                    soko += rr;
                    have -= tesu;
                }
            }
            m = max(m,have+soko);
        }
        cout << m << endl;
    }
}