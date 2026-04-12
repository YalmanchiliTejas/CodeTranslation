#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int d = min(a+b, c*2);

    int n = min(x,y);
    int cost = d*n;
    n = abs(x-y);

    if(x>y){
        if(2*c<a){
            cost += 2*c*n;
        }
        else{
            cost += a*n;
        }
    }
    else{
        if(2*c<b){
            cost += 2*c*n;
        }
        else{
            cost += b*n;
        }
    }

    cout << cost << endl;

    return 0;
}