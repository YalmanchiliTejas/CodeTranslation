#include <iostream>

using namespace std;

int main(void)
{
    int H = 0, N = 0;
    int max = 0;
    int count = 0;

   cin >> N;

    for(int i=0; i<N; i++){
        cin >> H;

        if(H >= max){
            max = H;
            count++;
        }
    }

    cout << count;

    return 0;
}