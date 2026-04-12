#include <iostream>
using namespace std;

int main(){
    int m;
    cin >> m;

    while( m-- > 0 ){
        int money, year, x;
        cin >> money >> year >> x;
        int Max = 0;

        while( x-- > 0 ){
            int type, h;
            double rate;
            cin >> type >> rate >> h;
            int t = money, n = 0;

            for( int i = 0; i < year; i++ ){
                if( type == 0 ){
                    n += t * rate;
                }else{
                    t += t * rate;
                }
                t -= h;
            }
            t += n;
            if( Max < t ) Max = t;
        }
        cout << Max << endl;
    }
}