   #include <bits/stdc++.h>
 
//    #include <boost/multiprecision/cpp_int.hpp>
 #define int long long
 #define inf  1000000007
// #define inf  998244353

 #define pa pair<int,int>
 #define ll long long
 #define pal pair<double,double>
 #define ppap pair<pa,int>
  #define PI 3.14159265358979323846
  #define paa pair<int,char>
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
 
                              
                int pr[100000];
                int inv[100000];
                

                
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
                
              //   cin.tie(0);
    		//	ios::sync_with_stdio(false);
    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
                 //sort(ve.begin(),ve.end(),greater<int>());
 //   mt19937(clock_per_sec);
  //  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;
  
int ad=0;
int zm=-inf;
int ban[2020][2020];

int T[2020];
int Y[2020];

void upd(int x,int y,int r){
	ban[x][y]=max(ban[x][y],r);
	T[x]=max(T[x],ban[x][y]);
	Y[y]=max(Y[y],ban[x][y]);
	zm=max(zm,ban[x][y]);
}

int tate(int r){
	return T[r];
}
int yoko(int r){
	return Y[r];
}


void solve(){
	int n;
	cin>>n;
	vector<int> ve(3*n);
	for(int i=0;i<3*n;i++)cin>>ve[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ban[i][j]=-inf,T[i]=-inf,Y[i]=-inf;
	
	upd(ve[0],ve[1],0);
	upd(ve[1],ve[0],0);
	

	for(int i=1;i<n;i++){
	//	ve[3*i-1];
	//	ve[3*i+1];
	//	ve[3*i];
		int ho[3]={ve[3*i-1],ve[3*i+1],ve[3*i]};
		sort(ho,ho+3);
		
		vector<pa3> kou; 
		if(ho[0]==ho[2]){
			ad++;
		}
		else if(ho[0]==ho[1] || ho[1]==ho[2]){
			int b;
			if(ho[0]==ho[1])b=ho[2];
			else b=ho[0];
			int a=ho[1];
			
			kou.pb((pa3){a,a,max(zm,ban[b][b]+1)});
			kou.pb((pa3){a,b,max(zm,ban[a][a]+1)});
			for(int i=1;i<=n;i++){
				kou.pb((pa3){a,i,tate(i)});
				kou.pb((pa3){i,a,yoko(i)});
			}
			for(int i=1;i<=n;i++){
				kou.pb((pa3){b,i,max(tate(i),ban[i][a]+1)});
				kou.pb((pa3){i,b,max(yoko(i),ban[a][i]+1)});
			}
			
		}
		else{
			int a=ho[0];
			int b=ho[1];
			int c=ho[2];
			
			kou.pb((pa3){a,b,max(zm,ban[c][c]+1)});
			kou.pb((pa3){a,c,max(zm,ban[b][b]+1)});
			kou.pb((pa3){b,c,max(zm,ban[a][a]+1)});
			
			
			for(int i=1;i<=n;i++){
				kou.pb((pa3){a,i,tate(i)});
				kou.pb((pa3){i,a,yoko(i)});
				kou.pb((pa3){b,i,tate(i)});
				kou.pb((pa3){i,b,yoko(i)});
				kou.pb((pa3){c,i,tate(i)});
				kou.pb((pa3){i,c,yoko(i)});
			
			}
		}
		for(auto v:kou)upd(v.x,v.y,v.z);
	}
	
	int g=ve.back();
	
	int ans=max(zm,ban[g][g]+1);
	cout<<ans+ad<<endl;
}

signed main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
int n=1;
	//cin>>n;

	
	for(int i=0;i<n;i++)solve();
	
	return 0;
 }

