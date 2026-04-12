#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;

    vector<int> ans(30, 0);
    for(int i = 0; i < n; i++)
    {
        vector<int> num(30, 0);
        string s;
        cin >> s;
        int len = s.size();
        for(int j = 0; j < len; j++)
        {
            int k = s[j] - 'a';
            num[k]++;
        }
        if(i == 0) ans = num;
        else
        {
            for(int k = 0; k < 26; k++)
            {
                ans[k] = min(ans[k], num[k]);
            }
        }
        
    }

    for(int i = 0; i < 26; i++)
    {
        int n = ans[i];
        for(int j = 0; j < n; j++)
        {
            cout << (char)(i+'a');
        }
        
    }
    
    cout << endl;
    
    
	return 0;
}