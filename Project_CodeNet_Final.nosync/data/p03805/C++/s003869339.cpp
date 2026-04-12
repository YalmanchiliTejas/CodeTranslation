#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int N,M;
bool a[8][8];

int main(){
    int x,y;
    long long count = 0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j] = false;
        }
    }
    for(int i=0;i<M;i++){
        cin >> x >> y;
        a[x-1][y-1] = a[y-1][x-1] = true;
    }
    int b[N];
    for(int i=0;i<N;i++){
        b[i] = i;
    }
    bool f;
    do{
        f = true;
        for(int i=0;i<N-1;i++){
            if(b[0] != 0){
                f = false;
                break;
            }
            if(a[b[i]][b[i+1]]) continue;
            f = false;
            break;
        }
        if(f) count++;
    }while(next_permutation(b, b + N));
    cout << count << endl;
    return 0;
}