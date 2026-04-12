#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, ans;
    vector<string> str;
    int n;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) cin>>s, str.push_back(s);
    int Size = str.size();
    int i=0;
    for(int i=0; i<str[0].length(); i++){
        int counter = 0;
        for(int j=1; j<str.size(); j++){
            for(int k=0; k<str[j].length(); k++){
                if(str[0][i]==str[j][k]){
                    counter++;
                    str[j][k] = '0';
                    break;
                }
            }
        }
        if(counter==n-1) ans += str[0][i];
    }

    sort(ans.begin(), ans.end());
    cout<<ans<<endl;

    return 0;
}
