#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long a,b,c,x,y,sum;
    cin>>a>>b>>c>>x>>y;
    if(x>y) {
        swap(x,y);
        swap(a,b);
    }
    if(a+b>2*c) {
        sum = 2*c*x + (y-x)*b;
    } else{
        sum = a*x+b*y;
    }
    if(sum > 2*c*y) sum = 2*c*y;
    cout << sum << endl;
}