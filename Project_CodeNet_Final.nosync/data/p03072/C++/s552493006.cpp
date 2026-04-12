#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int maxH=0;
    int H;
    int answer=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> H;
        if(H>=maxH){
            answer++;
            maxH=H;
        }
    }
    cout << answer;
    return 0;
}