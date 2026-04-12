#include <iostream>
using namespace std;
int main(void){
    int cnt = 0, max = 0, N;  cin >> N;
    for(int i=0; i<N; ++i){
        int a;  cin >> a;
        if(a >= max){
            cnt++;
            max = a;
        }
    }
    cout << cnt << endl;
}
