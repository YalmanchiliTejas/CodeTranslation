#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int c1[26] = {0};
    string a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    /**/
    for(int i = 0;i < n;i++){
        int c2[26] = {0};
        for(int j = 0;j < a[i].size();j++){
            int c = a[i].at(j) - 'a';
            c2[c]++;
        }
        if(i == 0){
            for(int i = 0;i < 26;i++){
                c1[i] = c2[i];
            }
        }
        else{
            for(int i = 0;i < 26;i++){
                c1[i] = min(c2[i],c1[i]);
            }
        }
    }
    /**/

    string ans;

    for(int i = 0;i < 26;i++){
        //cout << c1[i] << " ";
        if(c1[i] != 0){
            for(int j = 0;j < c1[i];j++){
                ans += i + 'a';
            }
        }
    }

    cout << ans << endl;

    return 0;
}