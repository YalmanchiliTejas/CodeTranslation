#include <iostream>
using namespace std;

int main(){
    int a, b, c, x ,y;
    long int sum = 20000000000;
    cin >> a >> b >> c >> x >> y;

    for(int i=0;i<=100000;i++){
        if(sum > 2*c*i+a*max(0, x-i)+b*max(0, y-i)){
            sum = 2*c*i+a*max(0, x-i)+b*max(0, y-i);
        }
    }
    cout << sum << endl;
    return 0;
}