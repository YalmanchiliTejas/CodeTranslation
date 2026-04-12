#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
typedef vector<int> vi;
#define rep(i, n) for(int i = 0; i <(n); ++i)
#define reps(i, m, n) for(int i = m; i < (n); ++i)
#define int long long

signed main(){
    
    
    
    set<char> right;
    right.insert('y');
    right.insert('h');
    right.insert('n');
    right.insert('u');
    right.insert('j');
    right.insert('m');
    right.insert('i');
    right.insert('k');
    right.insert('o');
    right.insert('l');
    right.insert('p');
    

     while (1)
     { int ans=0;
        string s;
        cin >> s; 
        if (s=="#")
        {
            break;
        }
        
    rep(i,s.size())
    {
        if (right.find(s[i])!=right.end())
        {
            s[i]='%';   
        }else
        {
            s[i]='$';
            
        }
        
    }
    
    for(int i=0;i<s.size()-1;i++){
        if(s[i] != s[i+1]){
            ans++;
        }
    }
    
    cout << ans << endl;
    }
    
    return 0;
}
