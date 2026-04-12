#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int res=1;
    
    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
        if(i!=0){
            bool can = true;
            for(int j=0;j<i;j++){
                if(h[j]>h[i]){
                    can = false;
                    break;
                }
            }
            if(can){
                res++;
            }
        }
    }
    
    
    cout << res << endl;
    
}
