#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    
    int H[100] = {};
    
    int n = N;
    int i = 0;
    
    while (n--){
        cin >> H[i];
        i++;
    }
    
    int view = 0;
    int max_H = 0;
    int a = 0;
    
    for(i=0;i<=N;i++){
        while(a<=i){
    max_H = max(max_H,H[a]);
           a++;
        if(max_H==H[i]){
            view++;
        }
        }
        
    }
    
    cout << view << endl;
    return 0;
}
