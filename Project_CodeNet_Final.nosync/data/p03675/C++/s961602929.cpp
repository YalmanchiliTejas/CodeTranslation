/*
    アリナ・グレイはかわいい
*/

#include<bits/stdc++.h>
using namespace std;
#define itn int
#define endl "\n"

int main(void){
    int n;
    cin >> n;
    int a[n];
    deque<int> d;
    for(int i = 0;i < n;i++)cin >> a[i];
    
    int back = 0;
    for(int i = 0;i < n;i++){
        back++;
        back %= 2;
        if(back == 0)d.push_front(a[i]);
        else d.push_back(a[i]);
    }
    
    if(back == 1)reverse(d.begin(),d.end());
    for(int i = 0;i < n;i++){
        cout << d[i];
        if(i == n-1)cout << endl;
        else cout << " ";
    }
 
}
