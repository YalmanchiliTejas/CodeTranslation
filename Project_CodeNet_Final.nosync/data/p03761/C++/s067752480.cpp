#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm> 
using namespace std;
 
# define p(s) std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
 
int main()
{
    int n;cin >> n;

    int al[26];
    for(int i=0;i<26;i++){
        al[i]=50;
    }

    int al_tmp[26]={};
    for(int i=0;i<n;i++){
        string s;cin >> s;

        for(int j=0;j<s.size();j++){
            al_tmp[(int)(s.at(j)-'a')]++;
        }
        for(int j=0;j<26;j++){
            al[j]=min(al[j],al_tmp[j]);
            al_tmp[j]=0;
        }
    }

    for(int i=0;i<26;i++){
        while(al[i]>0){
            cout << (char)('a'+i);
            al[i]--;
        }
    }
    cout << endl;

    return 0;
}