#include <iostream>
#include <vector>
int main(void){
        using namespace std;
        int N, c = 0, max = 0;
        cin >> N;
        vector<int> h(N);
        for(int i = 0; i < N; i++)
                cin >> h[i];
        for(int i = 0; i < N; i++){
                if( h[i] >= max){
                        c++;
                        max = h[i];
                }
        }
        cout << c << endl;
}
