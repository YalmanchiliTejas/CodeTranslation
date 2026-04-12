#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int h[30];
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++){
        int counter = 0;
        if(h[0] <= h[i]){
            for(int j = 0; j < i; j++){
                if(h[j] <= h[i]) counter++;
                }
                if(counter == i) ans++;
        }
    }
    cout << ans << endl;
}
