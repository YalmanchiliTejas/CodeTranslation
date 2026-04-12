#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int res = 0;
    a-=c;
    while (true) {
        if (a>=b+c){
            a-=b;
            res++;
        }
        a-=c;
        if (a<=0) break;
    }
    cout << res;
}
