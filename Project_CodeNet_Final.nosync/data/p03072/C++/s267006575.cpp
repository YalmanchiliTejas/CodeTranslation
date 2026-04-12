#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int H[N]; for(int i=0;i<N;i++) cin >> H[i];

    int counter = 0;
    bool flag = true;

    for(int i=0;i<N;i++){
        flag = true;
        for(int j=0;j<i;j++){
            if(H[j]>H[i]){
                flag = false;
                break;
            }
        }
        if(flag) counter++;
    }

    cout << counter;

    return 0;
}
