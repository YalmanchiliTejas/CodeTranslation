#include <iostream>
using namespace std;
int main()
{
    // 整数の入力
    int N;
    int H[20];
    int num,max_hight;

    cin >> N ;
    for (int i =0 ; i<N ; i++){
        cin >> H[i];
    }
    num = 0;
    max_hight = 0;
    for(int i = 0 ; i < N ; i++){
        if(H[i] >= max_hight){
            num = num + 1;
            max_hight = H[i];
        }
    }

    cout << num;

    return 0;
}