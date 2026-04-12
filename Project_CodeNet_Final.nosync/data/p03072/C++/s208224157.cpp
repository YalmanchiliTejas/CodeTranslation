#include <iostream>
#include <vector>
using namespace  std;
int main(){
    int N;
    int max = 0,cnt = 0;
    cin >> N;
    int H[N];
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    
    for(int i=0;i<N;i++){
        if(max <= H[i]){
            cnt++;
            max = H[i];
        }
    }
    cout << cnt << endl;
}