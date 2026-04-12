#include <iostream>
using namespace std;

int main() {
    long long k,a,b;
    cin >> k >> a >> b;
    if(b >= a && k > a) {
        cout << -1 << endl;
        return 0;
    }
    if(b >= a && k <= a) {
        cout << 1 << endl;
        return 0;
    }
    if(k<a) {
        cout << 1 << endl;
        return 0;
    }
    long long days = 0;
    if((k-a)%(a-b)==0){
        days = (k-a)/(a-b)*2+1;
    } else {
        days = (k-a)/(a-b)*2+2+1;
    }
    cout << days << endl;
    return 0;
}
