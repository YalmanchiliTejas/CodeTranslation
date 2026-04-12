#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[N];
    for(int i=0; i<N; i++){
        cin >> H[i];
    }
    int max_h=1;
    int res=0;
    for(int i=0; i<N; i++){
        if(H[i] >= max_h){
            res ++;
            max_h = H[i];
        }
    }
    cout << res << endl;
}
