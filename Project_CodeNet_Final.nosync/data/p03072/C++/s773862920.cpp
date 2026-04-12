#include <iostream>
using namespace std;

int main(void){
    int n, *h, count, flag;

    cin >> n;
    h = new int[n];
    for(int i = 0;i < n;i++){
        cin >> h[i];
    }

    count = 1;
    flag = 0;
    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            if(h[i] < h[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            count++;
        }
        flag = 0;
    }

    cout << count << endl;

    delete[] h;
    return 0;
}