#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    int i;
    for(i=0;i<N;i++)cin >> d[i];
    int m = 0;
    bool f = true;
    for(i=0;i<N;i++)if(m >= i*10)m = max(m,i*10+d[i]);
    if(m < 10*(N-1))f = false;
    m = 0;
    for(i=0;i<N;i++)if(m >= i*10)m = max(m,i*10+d[N-i-1]);
    if(m < 10*(N-1))f = false;
    cout << (f?"yes":"no") << endl;
}
