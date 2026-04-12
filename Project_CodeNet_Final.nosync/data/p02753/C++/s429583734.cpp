    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<long long> vll;
    typedef vector<pair<int , int>> vpii;
    typedef pair<int , int> pii;
    typedef pair<long long  , long long> pll;
    typedef pair<double , double> pdd;
    #define eb emplace_back;
    #define mp make_pair;
     
    int main(){
        string s;
        cin>>s;
        bool ok = false;
        for(int i = 0 ; i<s.length()-1 ; i++){
            if(s[i]!=s[i+1]){
                ok = true;
                break;
            }
        }
        if(ok){
            cout<<"Yes\n";
        } 
        else{
            cout<<"No\n";
        }
        return 0;
    }