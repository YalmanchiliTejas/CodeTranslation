          #include<bits/stdc++.h>     
                using namespace std;  
                typedef long long  ll;
                typedef pair<ll,ll> pll;  
                #define pb(x) push_back(x)     
                typedef unsigned long long  ull;     
                #define mem(A, X) memset(A, X, sizeof A)
                #define ford(i,l,u) for(ll (i)=(ll)(l);(i)>=(ll)(u);--(i))
                #define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
                #define fori(i,l,u) for(ll (i)=(ll)(l);(i)<=(ll)(u);++(i))    
                typedef pair<int,int> pii;
                #define sec second
                #define fir first  
              
                const ll mod=1e9+7; 
                const ll maxn=1e5+10; 
                  int n;
                  string s;
                  int animal[maxn];//1  s   0  w
                  void get_animal()
                  {
                    fori(i,2,n-1)
                    {
                      if(animal[i-1]==1) 
                      {
                        if(s[i-1]=='o') animal[i]=animal[i-2];
                        else animal[i]=!animal[i-2];
                      }
                      else 
                      { 
                        if(s[i-1]=='o') animal[i]=!animal[i-2];
                        else animal[i]=animal[i-2]; 
                      }
                    }
                  }
                  bool is_ok(int pos)
                  {
                    int pre=(pos+n-1)%n;
                    int nxt=(pos+n+1)%n;
                    if(animal[pos]==1) 
                    {
                      if(s[pos]=='o'&& animal[pre]==animal[nxt]) return true;
                       else if(s[pos]=='x'&& animal[pre]!=animal[nxt]) return true;
                        else return false;
                    }
                    else 
                    {
                      if(s[pos]=='o'&& animal[pre]!=animal[nxt]) return true;
                       else if(s[pos]=='x'&& animal[pre]==animal[nxt]) return true;
                        else return false;
                    }
                  }
                  bool check_ok()
                  { 
                      if( is_ok(n-1)&&is_ok(0) )  return true;
                      else return false; 
                  }
                  bool have_solve()
                  { 
                      animal[0]=0;
                      animal[1]=0;
                      get_animal();
                      if(check_ok()) return true;
                      animal[0]=0;
                      animal[1]=1;
                      get_animal();
                      if(check_ok()) return true;
                      animal[0]=1;
                      animal[1]=0;
                      get_animal();
                      if(check_ok()) return true;
                      animal[0]=1;
                      animal[1]=1;
                      get_animal();
                      if(check_ok()) return true; 

                      return false;
                  }
                int main()
                {
                     std::ios::sync_with_stdio(false); 
                    // freopen("in.txt","r",stdin); 
                    
                     while(cin>>n>>s)
                     {  
                      if(have_solve())  
                      {
                        fori(i,0,n-1) if(animal[i]==1) cout<<'S';else cout<<'W';  
                        cout<<endl;
                      }
                      else cout<<-1<<endl;
                     }
                     
                  return 0;
                }