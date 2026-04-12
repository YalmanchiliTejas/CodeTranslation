#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[N];
    for(int i=0;i<N;i++){ cin >> H[i]; }
    int count = 1;
    
    for(int i=1;i<N;i++){
        bool view = true;
        for(int j=0;j<i;j++){
            if(H[i] < H[j]){
                view = false;
                break;
            }
        }
        if(view){ count++; }
    }
    cout << count << endl;
}
