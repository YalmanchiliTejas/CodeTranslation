   #include <bits/stdc++.h>
//    #include <boost/multiprecision/cpp_int.hpp>
 #define int  long long
 #define inf  1000000007
 #define pa pair<int,int>
 #define ll long long
 #define pal pair<double,double>
  #define PI 3.14159265358979323846
  #define  mp make_pair
  #define  pb push_back
  #define EPS (1e-8)
                                          
    int dx[8]={0,1,0,-1,1,1,-1,-1};
    int dy[8]={1,0,-1,0,-1,1,1,-1};
                                            using namespace std;
                                   			class pa3{
                                            	public:
                                            	int x;
                                   				int y,z;
                                            	pa3(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}
                                            	bool operator < (const pa3 &p) const{
                                            		if(x!=p.x) return x<p.x;
                                            		if(y!=p.y) return y<p.y;
                                            		 return z<p.z;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                   				bool operator > (const pa3 &p) const{
                                            		if(x!=p.x) return x>p.x;
                                            		if(y!=p.y) return y>p.y;
                                            		 return z>p.z;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa3 &p) const{
                                            		return x==p.x && y==p.y && z==p.z;
                                            	}
                                            		bool operator != (const pa3 &p) const{
                                            			return !( x==p.x && y==p.y && z==p.z);
                                            	}
                                            
                                            };
                                            
                                            class pa4{
                                            	public:
                                            	int x;
                                            	int y,z,w;
                                            	pa4(int x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}
                                            	bool operator < (const pa4 &p) const{
                                            		if(x!=p.x) return x<p.x;
                                            		if(y!=p.y) return y<p.y;
                                            		if(z!=p.z)return z<p.z;
                                            		return w<p.w;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator > (const pa4 &p) const{
                                            		if(x!=p.x) return x>p.x;
                                            		if(y!=p.y) return y>p.y;
                                            		if(z!=p.z)return z>p.z;
                                            		return w>p.w;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa4 &p) const{
                                            		return x==p.x && y==p.y && z==p.z &&w==p.w;
                                            	}
                                            		
                                            
                                            };
                                            class pa2{
                                            	public:
                                            	int x,y;
                                            	pa2(int x=0,int y=0):x(x),y(y) {}
                                            	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
                                            	pa2 operator - (pa2 p) {return pa2(x-p.x,y-p.y);}
                                            	bool operator < (const pa2 &p) const{
                                            		return y != p.y ? y<p.y: x<p.x;
                                            	}
                                            	bool operator > (const pa2 &p) const{
                                            		return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa2 &p) const{
                                            		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                            	}
                                            	bool operator != (const pa2 &p) const{
                                            		return !(abs(x-p.x)==0 && abs(y-p.y)==0);
                                            	}
                                            		
                                            
                                            };
                                            
 
                      
                                string itos( int i ) {
                                ostringstream s ;
                                s << i ;
                                return s.str() ;
                                }
                                 
                                int Gcd(int v,int b){
                                	if(v==0) return b;
                                	if(b==0) return v;
                                	if(v>b) return Gcd(b,v);
                                	if(v==b) return b;
                                	if(b%v==0) return v;
                                	return Gcd(v,b%v);
                                }
                 
                            
                                int mod;
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
pa operator+(const pa & l,const pa & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
pa operator-(const pa & l,const pa & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}  
                int beki(int wa,int rr,int warukazu){
                	if(rr==0) return 1%warukazu;
                	if(rr==1) return wa%warukazu;
                	wa%=warukazu;
                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
                	ll zx=beki(wa,rr/2,warukazu);
                	return (zx*zx)%warukazu;
                }
 /*
                              
                int pr[1000100];
                int inv[1000110];
                

                
    			int comb(int nn,int rr){
    				if(rr<0 || rr>nn || nn<0) return 0;
    				int r=pr[nn]*inv[rr];
    				r%=mod;
    				r*=inv[nn-rr];
    				r%=mod;
    				return r;
    			}
               
                void gya(int ert){
                	pr[0]=1;
                	for(int i=1;i<=ert;i++){
                		pr[i]=((ll)pr[i-1]*i)%mod;
                	}
                		inv[ert]=beki(pr[ert],mod-2,mod);
                	for(int i=ert-1;i>=0;i--){
                		inv[i]=(ll)inv[i+1]*(i+1)%mod;
                	}
                }
               */ 
              //   cin.tie(0);
    		//	ios::sync_with_stdio(false);
    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
                 //sort(ve.begin(),ve.end(),greater<int>());
 //   mt19937(clock_per_sec);
  //  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;


unsigned long long ans[501][502]={};
int n;
unsigned long long s[510],t[510],u[510],v[510];
int memo[530][530];
	
void solve(int d){
		unsigned long long f=1;
	for(int i=0;i<d;i++){
		f*=2ULL;
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)memo[i][j]=-1;
	int yoko[610]={};
	
	for(int i=0;i<n;i++){
		if(s[i]==0){
			if(t[i]&(f)){
				for(int j=0;j<n;j++)memo[i][j]=1;
			}
			else{
				yoko[i]=1;
			}
		}
		else{
			if(!(t[i]&(f))){
				for(int j=0;j<n;j++)memo[i][j]=0;	
			}
			else{
				yoko[i]=2;
			}
		}
	}
	
	for(int j=0;j<n;j++){
		if(u[j]==0){
			if(v[j]&(f)){
				for(int i=0;i<n;i++)memo[i][j]=1;
			}
			else{
				//0がいる
				int e[4]={};
				bool bo=0;
				for(int i=0;i<n;i++){
					e[yoko[i]]++;
					if(memo[i][j]==0)bo=1;
				}
				if(bo){
					for(int i=0;i<n;i++)if(memo[i][j]==-1){
						if(yoko[i]==1){
							memo[i][j]=0;
							yoko[i]=3;
						}
						else if(yoko[i]==2){
							memo[i][j]=1;
							yoko[i]=3;
						}
						else{
							memo[i][j]=0;
						}
					}
				}
				else if(e[1]+e[3]>0){
					for(int i=0;i<n;i++)if(memo[i][j]==-1){
						if(yoko[i]==1 || yoko[i]==3){
							memo[i][j]=0;
							yoko[i]=3;
						}
						else {
							memo[i][j]=1;
							yoko[i]=3;
						}
					}
				}
				else{
					int cnt=0;
					for(int i=0;i<n;i++)if(memo[i][j]==-1){
						if(cnt==0){
							memo[i][j]=0;
							//yoko[i]=3;
							cnt++;
						}
						else{
							memo[i][j]=1;
							yoko[i]=3;
						}
					}
				}
			}
		}
		else{
			if(!(v[j]&(f))){
				for(int i=0;i<n;i++)memo[i][j]=0;
			}
			else{
				//1がいる
				int e[4]={};
				bool bo=0;
				for(int i=0;i<n;i++){
					e[yoko[i]]++;
					if(memo[i][j]==1)bo=1;
				}
				if(bo){
					for(int i=0;i<n;i++)if(memo[i][j]==-1){
						if(yoko[i]==1){
							memo[i][j]=0;
							yoko[i]=3;
						}
						else if(yoko[i]==2){
							memo[i][j]=1;
							yoko[i]=3;
						}
						else{
							memo[i][j]=0;
						}
					}
				}
				else if(e[2]+e[3]>0){
					for(int i=0;i<n;i++)if(memo[i][j]==-1){
						if(yoko[i]==2 || yoko[i]==3){
							memo[i][j]=1;
							yoko[i]=3;
						}
						else if(yoko[i]==1){
							memo[i][j]=0;
							yoko[i]=3;
						}
					}
				}
				else{
					int cnt=0;
					for(int i=0;i<n;i++)if(memo[i][j]==-1){
						if(cnt==0){
							memo[i][j]=1;
							//yoko[i]=3;
							cnt++;
						}
						else{
							memo[i][j]=0;
							yoko[i]=3;
						}
					}
				}				
				
				
			}
		}
	}
	

	//cout<<f<<endl;
for(int i=0;i<n;i++)for(int j=0;j<n;j++){
	if(memo[i][j]==1)ans[i][j]^=f;
}
	
	
}

signed main(){
cin.tie(0);
ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)cin>>u[i];
	for(int i=0;i<n;i++)cin>>t[i];
	for(int i=0;i<n;i++)cin>>v[i];
	
	for(int i=0;i<64;i++)solve(i);
	
	
	for(int i=0;i<n;i++){
		unsigned long long g=ans[i][0];
		for(int j=1;j<n;j++){
			if(s[i]==1)g|=ans[i][j];
			else g&=ans[i][j];
		}
		if(g!=t[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	
	for(int j=0;j<n;j++){
		unsigned long long g=ans[0][j];
		for(int i=1;i<n;i++){
			if(u[j]==1)g|=ans[i][j];
			else g&=ans[i][j];
		}
		if(g!=v[j]){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
 }

