#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Abs(a,b) max(a,b)-min(a,b)
#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define Cout(x) cout<<(x)<<endl
#define POSSIBLE(condition) if(condition){cout << "POSSIBLE" << endl;}else{cout << "IMPOSSIBLE" << endl;}
#define Possible(condition) if(condition){cout << "Possible" << endl;}else{cout << "Impossible" << endl;}
#define possible(condition) if(condition){cout << "possible" << endl;}else{cout << "impossible" << endl;}
#define Size(n) (n).size()

typedef long long ll;


using namespace std;

const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;
const ll LINF = 1e18;


long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x[ohara],y[ohara],sum=0,pos,data[ohara];
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

      
      cin>>n;
      map<pair<ll,ll>,ll> graph;
      map<ll,ll> ac;
      map<ll,ll> wa;
      ll rmi=LINF,rma=0,bmi=LINF,bma=0,ma=0,mi=LINF;
      priority_queue<ll> que;
      rep(i,n){
        cin>>x[i]>>y[i];
        if(y[i]<x[i]){
            pos=y[i];
            y[i]=x[i];
            x[i]=pos;
        }
        ma=max(ma,max(x[i],y[i]));
        mi=min(mi,min(x[i],y[i]));
        rmi=min(rmi,min(x[i],y[i]));
        rma=max(rma,min(x[i],y[i]));
        bmi=min(bmi,max(x[i],y[i]));
        bma=max(bma,max(x[i],y[i]));
        graph[{ac[y[i]]++,y[i]}]=x[i];
      }
      ans=(rma-rmi)*(bma-bmi);
      //Cout(ans);
      rep(i,n){
        if((x[i]==mi&&y[i]==ma)||(x[i]==ma&&y[i]==mi))cnt++;
      }
      
      if(cnt==1)Cout(ans);
      else{
        sum=LINF;
        ll miflag,maflag,migroup[ohara],magroup[ohara];
        rep(i,n){
          if(mi==x[i]||mi==y[i]){
            if(sum>=x[i]+y[i]){
              sum=x[i]+y[i];
              miflag=i;
            }
          }
        }
        sum=0;
        rep(i,n){
          if(ma==x[i]||ma==y[i]){
            if(sum<=x[i]+y[i]){
              sum=x[i]+y[i];
              maflag=i;
            }
          }
        }
        pos=ma-mi;
        cnt=0;
        ll maa=ma,mii=mi;
        ma=0,mi=LINF;
        cmp=miflag;cmpp=maflag;
        if(x[miflag]==mii){
            ma=max(ma,y[miflag]);
            mi=min(mi,y[miflag]);
            
         // migroup[cnt]=y[miflag];
          //magroup[cnt]=x[miflag];
          miflag=LINF;
          //cnt++;
        }
        if(miflag!=LINF){
            ma=max(ma,x[miflag]);
            mi=min(mi,x[miflag]);
          //migroup[cnt]=x[miflag];
         //magroup[cnt]=y[miflag];
          //cnt++;
        }
        //Cout(mi);

        if(x[maflag]==maa){
            ma=max(ma,y[maflag]);
            mi=min(mi,y[maflag]);
           // Cout(mi);
         // migroup[cnt]=y[maflag];
          //magroup[cnt]=x[maflag];
          maflag=LINF;
          //cnt++;
        }
        if(maflag!=LINF){
            ma=max(ma,x[maflag]);
            mi=min(mi,x[maflag]);
          //migroup[cnt]=x[maflag];
          //magroup[cnt]=y[maflag];
         // cnt++;
        }
        ll tle,re;
        tle=ma;re=mi;
        
        miflag=cmp;
        maflag=cmpp;
        //cout<<ma<<" "<<mi<<"\n";
        
        rep(i,n){
            if(i==miflag||i==maflag)continue;
            fl=true;
            magroup[cnt]=min(x[i],y[i]);
            migroup[cnt]=max(x[i],y[i]);
            ma=max(ma,migroup[cnt]);
            mi=min(mi,migroup[cnt]);
            //Cout(migroup[cnt]);
            a=migroup[cnt];
            que.push(a);
            cnt++;
        }
        
        if(!fl){
            Cout(ans);
            return 0;
        }
        
        sort(magroup,magroup+cnt);
        reverse(magroup,magroup+cnt);
        
        ll anss=ma-mi,cntt=0;
       // cout<<tle<<" "<<ma<<"\n";
        if(tle!=ma){
        
        //Cout(que.top());
        //Cout(anss);
        
        
        while(!que.empty()){
            
            a=graph[{wa[que.top()]++,que.top()}];
            //cout<<a<<" "<<que.top()<<"\n";
            cmp=que.top();
            que.pop();
            if(max(tle,max(que.top(),a))-min(mi,a)>ma-mi){
                que.push(cmp);
                cntt++;
              if(cntt>=n-2)break;
                continue;
            }
            que.push(a);
            ma=max(tle,que.top());
            mi=min(mi,a);
            anss=min(anss,ma-mi);
            //cout<<ma<<" "<<mi<<"\n";
            //Cout(anss);
            cntt++;
          if(cntt>=n-2)break;
            
        }
        }
        
        //cout<<pos<<" "<<anss<<"\n";
        
        ans=min(ans,pos*anss);
        
        
        
        
        
        Cout(ans);
      }
     
     

       
return 0;
}
