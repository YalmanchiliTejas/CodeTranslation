#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    int x,y;
    cin >> x >> y;
    int cost=a*x+b*y;

    if(x<y){
        swap(x,y);
        swap(a,b);
    }

    cost=min(cost,a*(x-y)+2*y*c);
    cost=min(cost,2*x*c);

    cout << cost << endl;
}