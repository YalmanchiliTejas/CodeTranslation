#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, tmp, max, count;
    cin >> N;
    cin >> max;
    count = 1;
    for(int i=1;i<N;i++){
        cin >> tmp;
        if(tmp >= max){
            count++;
            max = tmp;
        }
    }

    cout << count << "\n";
    return 0;
}
