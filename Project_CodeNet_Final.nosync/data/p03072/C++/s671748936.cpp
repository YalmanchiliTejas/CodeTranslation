#include <iostream>

using namespace std;

int main(void){
    int n,h[20],res=1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    for(int i=1;i<n;i++){
        int flag = 1;
        for(int j=0;j<i;j++){
            if(h[j] > h[i])flag = 0;
        }
        if(flag)res++;
    }
    cout << res << endl;
}