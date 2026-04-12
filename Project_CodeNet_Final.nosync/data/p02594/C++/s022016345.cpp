    #include <bits/stdc++.h>
    using namespace std;
    typedef unsigned long long ull;
    typedef long long ll;
    typedef long double ld;
    #define FOR(type,a,b,c,d) for(type i = a;i b c;i += d)
    #define QUICK ios_base::sync_with_stdio(0);cout << fixed;
    #define MOD 1000000007

    string upper(string);
    string lower(string);
    bool isalup(string);
    bool isalow(string);

    int main(){

        int a;
        cin >> a;
        cout << (a>=30?"Yes":"No");
    

        return 0;
    }









                string upper(string a){
                    for(char& c:a){
                        if(islower(c))
                            c -= 32;
                       }
                    return a;
                }
                    string lower(string a){
                        for(char& c : a){
                            if(isupper(c))
                                c += 32;
                        }
                        return a;
                    }
                    bool isalup(string a){
                        for(char& c: a){
                            if(islower(c))
                                return false;
                        }
                        return true;
                    }
                    bool isalow(string a){
                        for(char& c:a){
                            if(isupper(c))
                                return false;
                        }
                       return true;
                    }
