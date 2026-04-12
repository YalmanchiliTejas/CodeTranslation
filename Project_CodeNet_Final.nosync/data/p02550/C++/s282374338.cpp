   #include <bits/stdc++.h>
 //#include<atcoder/all>
//    #include <boost/multiprecision/cpp_int.hpp>
 #define int long long
 #define inf  1000000007
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
 
                              
                int pr[400100];
                int inv[400010];
                

                
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
  

struct segsum{
	//       1
	//   2        3
	// 4   5   6    7
	
	
	private:
	public:
	
	// 1<<15 = 32768
	// 1<<16 = 65536
	// 1<<17 = 131072
	// 1<<18 = 262144
	
	int cor=(1<<18);
	
	vector<int> vec;
	
	void shoki1(){
		vec.resize(2*cor+3, 0);
	}
	void shoki2(){
		for(int i=cor-1;i>0;i--) vec[i]=vec[2*i]+vec[2*i+1];
	}
	void clear(){    
	    for(int i=0;i<(int)vec.size();i++)vec[i]=0;
    }
	
	void updadd(int x,int w){
		//x 項目に w加算
		x+=cor;
		vec[x]+=w;
		x/=2;
		while(x){
			vec[x]=vec[2*x]+vec[2*x+1];
			x/=2;
		}
	}
	
	void updchan(int x,int w){
		//x項目をwに変更
		x+=cor;
		vec[x]=w;
		while(x){
			x/=2;
			vec[x]=vec[2*x]+vec[2*x+1];
		}		
	}
	
	// [a,b)
	int sum(int a,int b){
		int hi=0,mi=0;
		a+=cor,b+=cor;
		while(a<b){
			if(a&1){
				hi=hi+vec[a];
				a++;
			}
			if(b&1){
				b--;
				mi=vec[b]+mi;
			}
			a/=2,b/=2;
		}
		return hi+mi;
	}
	
	// 位置pからはじめて和がx以上になる位置．ない場合はcorが返る
	int lower_bound(int p,int x){
		p+=cor;
		int ima=0;
		while(1){
			while(!(p&1))p/=2;
			if(ima+vec[p]>=x)break;//条件を満たさなくなる
			ima=ima+vec[p];
			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			if(ima+vec[p]<x){//条件を満たす
				ima+=vec[p];
				p++;
			}
		}
	}
	
	// 位置pからはじめて和がxより大になる位置．ない場合はcorが返る
	int upper_bound(int p,int x){
		p+=cor;
		int ima=0;
		while(1){
			while(!(p&1))p/=2;
			if(ima+vec[p]>x)break;//条件を満たさなくなる
			ima=ima+vec[p];
			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			if(ima+vec[p]<=x){//条件を満たす
				ima+=vec[p];
				p++;
			}
		}
	}	
	
};

ostream& operator<<(ostream& os, const pa& PAI){
	os<<PAI.first<<" : "<<PAI.second;
    return os;
}
int itu[100020];
vector<int> rui;
void solve(){
	
	vector<int> ve;
	int n,m,x;
	cin>>n>>x>>m;
	ve.pb(x);
	for(int i=0;i<m;i++)itu[i]=-1;
	itu[x]=0;
	int wa=x;
	rui.pb(x);
	while(1){
		int g=(x*x)%m;
		
		if(itu[g]==-1){
			itu[g]=ve.size();
			ve.pb(g);
			wa+=g;
			rui.pb(wa);
		//	cout<<wa<<endl;
			//cout<<wa<<endl;
			x=g;
		}
		else{
			int shu=ve.size()-itu[g];
			int sho=itu[g];
			
			if(n<=sho){
				
				cout<<rui[n-1]<<endl;
				return;
			}
			n-=sho;
		//	cout<<shu<<" "<<g<<endl;
			int d=n/shu;
			int amari=n%shu;
			int q=0;
			for(int i=0;i<amari;i++){
				q+=g;
				g=(g*g)%m;
			}
			int wa=0;
			for(int i=sho;i<ve.size();i++)wa+=ve[i];
			
		//	cout<<rui[sho-1]<<endl;
			int ff=0;
			if(sho)ff=rui[sho-1];
			cout<<ff+d*wa+q<<endl;
			break;
		}
	}
	
	
	
}



signed main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);

int n=1;
	//cin>>n;
	for(int i=0;i<n;i++){
		solve();

	}
 }
