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
  
  int BL[6030];
  int memo_bl[6030];
int nx(int g){
	
	if(g==inf)return inf;
	return memo_bl[g];
}
int rui[6030]={};
int hani(int x,int y){
	if(x>=y)return 0;
	return rui[y-1]-rui[x-1];
}
int N;
vector<int>V;
map<pa3,int> ma;

int solve(int bl,int dame,int tugi){
//	cout<<bl<<" "<<dame<<" "<<tugi<<endl;
	if(bl>=N)return 0;
	if(tugi<3*bl-2) tugi=-1;
	if(!(3*bl-2<=dame && dame<=3*bl))dame=-1;
	if(dame>=0&&tugi>=0)if(dame>tugi)swap(dame,tugi);
//	cout<<bl<<" "<<dame<<" "<<tugi<<endl;

	pa3 yyy=(pa3){bl,dame,tugi};
//	cout<<"DP "<<yyy.x<<" "<<yyy.y<<" "<<yyy.z<<" "<<memo_bl[6]<<endl;
	if(ma.count(yyy))return ma[yyy];
	
	int ans=solve(bl+1,dame,tugi);
	for(int r=3*bl-2;r<=3*bl;r++){
		
		
		int z=nx(r);
		int zz=nx(z);
		
		if(r==dame || r==tugi)continue;
		if(zz==dame || z==tugi)continue;
		if(z==dame || zz==tugi)continue;

		if(zz==inf)continue;

		
		if(zz==3*bl){
			ans=max(ans,solve(bl+1,dame,tugi)+1);
			continue;
		}
		if(z<=3*bl){
				int A=(tugi+2)/3;
			int B=(zz+2)/3;
			if(tugi<=3*bl){
	
				ans=max(ans,solve(bl+1,-1,zz)+1);
			}
			else if(A<=B){
				ans=max(ans,hani(bl+1,A)+solve(A,tugi,zz)+1);
			}
			else{
				ans=max(ans,hani(bl+1,B)+solve(B,zz,tugi)+1);	
			}
			continue;
		}
		{
			int A=(tugi+2)/3;
			if(A>bl)continue;
			int B=(z+2)/3;
			//int C=(zz+2)/3;
			ans=max(ans,hani(bl+1,B)+solve(B,z,zz)+1);
		}

	}
	
	/*
	int noko[3]={};
	for(int i=3*bl-2;i<=3*bl;i++){
		if(i==dame||i==tugi)continue;
		noko[i-(3*bl-2)]=1;
	}
	int ans=solve(bl+1,dame,tugi);

	
	for(int r=1;r<8;r++){
		bool baka=0;
		int pp=-1;
		for(int i=0;i<3;i++)if(r&(1<<i)){
			if(noko[i]==0){
				baka=1;
				break;
			}
			if(pp==-1)pp=V[3*bl-2+i];
			else if(pp!=V[3*bl-2+i]){
				baka=1;
				break;
			}
			
		}
		if(baka)continue;
	//	cout<<r<<endl;
		if(r==7){
			ans=max(ans,solve(bl+1,dame,tugi)+1);
			continue;
		}
		else if(r==6 || r==5 || r==3){
			int z;
			if(r!=3)z=nx(3*bl);
			else z=nx(3*bl-1); 
			if(z==inf)continue;
			int A=(z+2)/3;
			int B=(tugi+2)/3;
			if(A==bl)continue;
			if(tugi==-1){
				ans=max(ans,hani(bl+1,A)+solve(A,z,tugi)+1);
			}
			else if(A<B){
				ans=max(ans,hani(bl+1,A)+solve(A,z,tugi)+1);
			}
			else if(A==B){
				ans=max(ans,hani(bl+1,A)+solve(A,z,tugi)+1);
			}
			else if(A>B){
				ans=max(ans,hani(bl+1,B)+solve(B,tugi,z)+1);	
			}
		}
		else{
			int B=(tugi+2)/3;
			if(bl<B)continue;
			int z;
			if(r==1)z=nx(3*bl-2);
			if(r==2)z=nx(3*bl-1);
			if(r==4)z=nx(3*bl);
			
			//cout<<z<<endl;
			if(z==inf)continue;
			int z2=nx(z);
			if(z2==inf)continue;
			
			int A1=(z+2)/3;
			int A2=(z2+2)/3;
			if(A1==bl ){
				continue;
			}
			if(A1==A2){
				ans=max(ans,hani(bl+1,A1)+solve(A1,z,z2)+1);
			}
			else{
				ans=max(ans,hani(bl+1,A1)+solve(A1,z,z2)+1);		
			}
		}
		
	}
	*/
	ma[yyy]=ans;
	
	//cout<<"dp "<<yyy.x<<" "<<yyy.y<<" "<<yyy.z<<" "<<ans<<endl;
	return ans;
}


int dfs(vector<int> ve){
	if((int)ve.size()==3){
		if(ve[0]==ve[1]&&ve[1]==ve[2])return 1;
		return 0;
	}
	int g=ve.size();
	vector<int> w;
	for(int i=g-5;i<g;i++){
		w.pb(ve.back());
		ve.pop_back();
	}
	
	string s="00011";
	int ans=-inf;
	do{
		set<int> se;
		for(int i=0;i<5;i++){
			if(s[i]=='1'){
				ve.pb(w[i]);
			}
			else{
				se.insert(w[i]);
			}
		}
		if(se.size()==1)ans=max(ans,1+dfs(ve));
		else ans=max(ans,dfs(ve));
		ve.pop_back();
		ve.pop_back();
		
	}while(next_permutation(s.begin(),s.end()));
	return ans;
}


void solve(){
	ma.clear();
	int n;
	//n=4;
	cin>>n;
	N=n;
	vector<int> ve(3*n);
	for(int i=0;i<3*n;i++){
		cin>>ve[i];
	//	ve[i]=rand()%n+1;
	}
	reverse(ve.begin(),ve.end());
	for(int i=1;i<=n;i++)BL[i]=inf;
	for(int i=3*n-1;i>=0;i--){
		memo_bl[i]=BL[ve[i]];
		BL[ve[i]]=i;
	}
	for(int bl=1;bl<n;bl++){
		rui[bl]=0;
		if(ve[3*bl-2]==ve[3*bl-1] && ve[3*bl-1]==ve[3*bl])rui[bl]=1;
		rui[bl]+=rui[bl-1];
	}
	rui[n]=rui[n-1];
	V=ve;
	int ans=solve(1,-1,-1);
	
	int z=nx(0);
	//cout<<ans<<endl;
	if(z!=inf){
		int zz=nx(z);
		if(zz!=inf){
			
			ans=max(hani(1,(z+2)/3)+solve((z+2)/3,z,zz)+1,ans);
		}
	}
	/*
	if(dfs(ve)-ans!=0){
		for(auto v:ve)cout<<v<<" ";
		cout<<endl;
		cout<<dfs(ve)<<" "<<ans<<endl;
		exit(0);
	}
	*/
//	cout<<dfs(ve)-ans<<endl;
	cout<<ans<<endl;
}

signed main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
int n=1;
	//cin>>n;

	
	for(int i=0;i<n;i++)solve();
	
	return 0;
 }

