#include<bits/stdc++.h>
using namespace std;

int main()
{
  	int n;
  	cin>>n;
  	string s[n];
  	for(int i = 0; i < n; i++)
      cin>>s[i];
  	int m[n][26];
  	memset(m, 0, sizeof(m));
  	for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < s[i].length(); j++)
          	m[i][s[i][j]-'a'] += 1;
    }
  	//string res = "";
  	for(int j = 0; j < 26; j++)
    {
      	int mi = INT_MAX, flag = 0;
    	for(int i = 0; i < n; i++)
        {
        	if(m[i][j] == 0)
            {
              	flag = 1;
              	break;
            }
          	mi = min(mi, m[i][j]);
        }
      	if(flag == 0)
        {
          	for(int k = 0; k < mi; k++)
              	cout<<char('a'+j);
        }
    }
	return 0;
}