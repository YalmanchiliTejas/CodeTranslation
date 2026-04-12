#include <iostream>

using namespace std;

int main(){
    int N, ans, i, Max;
    ans = 1;
    cin >> N;
    int M[30];
    for(i=0;i<N;i++){
        cin >> M[i];
    }

    Max = M[0];
    
    for( i = 0; i < N-1; i++)
    {
        if (M[i+1] >= Max) {
            ans += 1;
            Max = M[i+1];
        }
    }
    

    cout << ans << endl;
}