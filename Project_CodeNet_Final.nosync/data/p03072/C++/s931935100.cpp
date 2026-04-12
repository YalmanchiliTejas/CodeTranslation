#include <iostream>
#include <string>
#include <map>
#include <math.h>
using namespace std;

#define ll long long

int main(){
    int N;
    cin >> N;
    int H[N];
    for(int i = 0;i < N;i++)cin >> H[i];
    int h = 0,count = 0;
    for(int i = 0;i < N;i++){
        if(h <= H[i]){
            h = H[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}