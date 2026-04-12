#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int count=0;
    int m=0;
    int height;
    cin >> n;

    while(cin >> height){
        if(m <= height){
            count++;
        }
        //cout << height;
        m = max(m,height);
    }

    cout << count;

    return 0;
}
