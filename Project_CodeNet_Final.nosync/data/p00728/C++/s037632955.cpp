#include <iostream>
using namespace std;

int main(){
    int n;
    int high,low;
    int hi,lo;
    int total;
    int cnt;
    int point[100]={0};
    while(1){
        total = 0;
        cnt = 0;
        cin >> n;
        if(n == 0) break;
        for(int i=0;i<n;i++){
            cin >> point[i];
            if(i == 0){
                high = point[i];
                low = point[i];
                hi = 0;
                lo = 0;
            }
            else if(point[i] > high){
                high = point[i];
                hi = i;
            }
            else if(point[i] < low){
                low = point[i];
                lo = i;
            }
        }
        for(int i=0;i<n;i++){
            if(i != hi && i != lo){
                total += point[i];
                cnt++;
            }
        }
        cout << total / cnt << endl;
    }
}