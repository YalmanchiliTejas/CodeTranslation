#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> vec;
    int max;
    int in;
    cin >> max;
    //cout << max <<endl;
    int ans = n;
    //cout << ans <<endl;
    for(int i=0;i<n-1;i++){
        cin >> in;
        //cout << in << max;
        if(max>in){
            ans--;
        }
        else{
            max = in;
        }
       // cout << ans << endl;
    }
    cout << ans;

    return 0;
}