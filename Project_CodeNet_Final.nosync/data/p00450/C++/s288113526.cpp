#include<iostream>
using namespace std;

int stones;
int i;
int n;
int change[100000];
int change_i;
int last;

int solve(int color){
    int a=1;
    if(i & 1 && last != color){
        color ? stones-=i-change[change_i-1] : stones+=i-change[change_i-1];
        a=0;
    }
    if(!color) stones++;
    i++;
    return a;
}

int main(){
    int color;
    cin >> n;
    while(n){
        i = 0;
        last = 2;
        stones = 0;
        change_i = 0;
        for(int j=0;j<n;j++){
            cin >> color;
            if(solve(color)){
                if(last != color){
                    change[change_i] = j;
                    change_i++;
                }
            }else if(change_i>1){
                change_i--;
            }
            /*for(int k=0;k<change_i;k++){
                cout << change[k] << " ";
            }
            cout << endl;
            */
            last = color;
        }
        cout << stones << endl;
        cin >> n;
    }
}