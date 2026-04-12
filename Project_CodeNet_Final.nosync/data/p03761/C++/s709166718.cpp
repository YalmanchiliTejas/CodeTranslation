#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[26];// = {5000};
    //cout << arr[0] << endl;
    //memset(arr, 5000, sizeof(arr));
    for(int i=0; i<26; i++) arr[i] = 5001;
    int n ;cin>> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        int new_arr[26];
        memset(new_arr, 0, sizeof(new_arr));
        for(int ii=0; ii<s.length(); ii++){
            new_arr[s[ii]-'a'] += 1;
        }
        //for(int l = 0; l<26; l++) cout << new_arr[l]<< " ";
        //cout << endl;
        for(int ii=0; ii<26; ii++){
            arr[ii] = min(arr[ii], new_arr[ii]);
            //cout << arr[ii] << " ";
        }
        //cout << endl;
    }
    //for(int i=0;i<26; i++) cout << arr[i]  <<" ";
    //cout << endl;
    string ans = "";
    for(int i=0; i<26; i++){
        if(arr[i] == 5000) continue;
        for(int j=0; j<arr[i]; j++){
            ans += 'a'+i;
        }
    }
    cout << ans << endl;
}