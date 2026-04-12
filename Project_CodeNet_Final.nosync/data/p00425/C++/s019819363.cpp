#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n;
    string operation;
    int sum;
    int current_num;
    while(cin >> n){
        if(n==0)return 0;
        sum = 1;
        current_num = 1;
        int deme[] = {2,5,4,3};
        for(int i = 0; i < n; i++){
           cin >> operation;
           if (operation == "North"){
                int d = deme[0];
                sum += deme[0];
                deme[0] = 7 - current_num;
                deme[1] = current_num;
                current_num = d;
           }
           else if (operation == "South"){

                int d  = deme[1];
                sum += deme[1];
                deme[0] = current_num;
                deme[1] = 7 - current_num;
                current_num = d;
           }
           else if (operation == "East"){
                int d = deme[2];
                sum += deme[2];
                deme[2] = 7 - current_num;
                deme[3] = current_num;
                current_num = d;
           }
           else if (operation == "West"){
                int d = deme[3];
                sum += deme[3];
                deme[2] = current_num;
                deme[3] = 7 - current_num;
                current_num = d;
           }
           else if (operation == "Right"){
                int swap_n = deme[0];
                int swap_s = deme[1];
                deme[0] = deme[3];
                deme[1] = deme[2];
                deme[2] = swap_n;
                deme[3] = swap_s;
                sum += current_num;
           }
           else if (operation == "Left"){
                int swap_n = deme[0];
                int swap_s = deme[1];
                deme[0] = deme[2];
                deme[1] = deme[3];
                deme[2] = swap_s;
                deme[3] = swap_n;
                sum += current_num;
            }
        }
        cout << sum << endl;
    }
    return 0;
}