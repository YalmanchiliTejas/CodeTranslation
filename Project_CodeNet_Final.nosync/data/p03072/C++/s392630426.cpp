#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,t;
    cin >> t;
    int h[t];
    int temp = 0, tot = 0, highest=0;
    for(i=0;i<t;i++){
        cin >> h[i];

        if(h[i]>highest) highest = h[i];

        if(h[i]>=temp && h[i]>=highest)
            temp = h[i];
        else{

            tot++;
            temp = h[i];
        }

    }

    cout << t-tot << endl;
}
