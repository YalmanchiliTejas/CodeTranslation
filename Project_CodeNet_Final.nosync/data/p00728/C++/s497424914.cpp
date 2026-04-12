#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0){
        vector < int > s(n);
        int min = 1001;
        int max = -1;
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> s[i];
            if(s[i] < min){
                min = s[i];
            }
            if(s[i] > max){
                max = s[i];
            }
            total += s[i];
       }

       cout << (total-min-max)/(n-2) << endl;
       cin >> n;
    }
}
