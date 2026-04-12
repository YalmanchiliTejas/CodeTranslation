#include<iostream>
#include<algorithm>
using namespace std;

void score(int x){
    int n;
    int point[102];
    int ave = 0;

    n = x;
    for(int i=0;i<n;i++) cin >> point[i];
    sort(point,point+n);
    for(int i=1;i<n-1;i++){
        ave += point[i];
    }
    cout << ave / (n - 2) << endl;
}

int main(){
    int x;
    while(1){
        cin >> x;
        if(x == 0) break;
        score(x);
    }
    
    return 0;
}
