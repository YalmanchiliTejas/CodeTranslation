#include <iostream>
using namespace std;
int main(void){
    int n, count, high;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    count = 1;
    high = h[0];
    for(int i = 1; i < n; i++){
        
        if(high <= h[i]){
            count ++;
            high = h[i];
        }
        
        /*
        if(h[i-1] < h[i]){
            for(int j = i-1; j >= 0; j--){
                
                if(h[j] < h[i]){
                    count++;
                    
                }
            }
        }else{
            break;
        }
        */
        
    }
    /*
    for(int i = 1; i < n; i++){
        if(h[0] <= h[i] && h[1] <= h[i] && h[i-1] <= h[i]){
            count++;
        }
    }*/
    printf("%d\n", count);
}
