#include <iostream>
using namespace std;

int main(){
    int m;
    cin >> m;
    for(int i=0; i<m; ++i){
        int result, amount, year, n, max = 0;
        cin >> amount;
        cin >> year;
        cin >> n;
        for(int j=0; j<n; ++j){
            int a = amount;
            int kind, t;
            double r;
            scanf("%d %lf %d", &kind, &r, &t);
            if(kind == 0){
                int b = 0;
                for(int k=0; k<year; ++k){
                    b += (a * r);
                    a -= t;
                }
                result = a + b;
            }else{
                for(int k=0; k<year; ++k) a+=(a*r-t);
                result = a;
            }
            if(max < result) max = result;
        }
        cout << max << endl;
    }
    return 0;
}