#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

ll n,m,k,l;
vector<pair<int,string> > score;
map<string,int> dns;
map<string,int> ranks; 
vector<string> favs;
vector<int> favsRanks;
vector<int> favsDns;
char buf[1000];

// tlðãÊklÉüêé±ÆªÂ\©
bool check(int t){
    if(t>k)
        return false;
    else{
        ll sum=0;
        int ms;
        string mname;
        // tlÌ¤¿Ak-tÈãÌÊðæÁÄ¢éàÌÍ³µA»ÌÙ©Ì¨ÉÂ¢Äl¦é
        bool f=false;
        int p=0;
        for(int i = 0; i < t; i++){
            // A±µÄÊªßçêéÆ±ëÜÅßé
            // »ÝÌÊuÌÜÜÅàcèÌvf·×Äªüè¤é©Ç¤©
            int rfi=favsRanks[i];
            if(!f&&(k-rfi)>=t-i-1)
                continue;
            // à¤ß«êÈ¢ÌÅAæÃ~ÉÊðã¸³¹é
            if(!f){
                ms=score[k+i-t].first;
                mname=score[k+i-t].second;
                f=true;
            }
            // cÁ½àÌðüêéÉ«èépÉ}ü
            ll diff=-favsDns[i]+ms;
            if(mname<favs[i])
                diff++;
            sum+=diff;
        }
        return (sum<=l);
    }
}

void solve(){
    while(cin>>n>>m>>k>>l&&!(n==0&&k==0&&m==0&&l==0)){
        score.clear();favs.clear();dns.clear();ranks.clear();
        favsRanks.clear();
        favsDns.clear();
        for(int i = 0; i < n; i++){
            int s;
            string name;
            //scanf("%s %d\n",buf,&s);
            cin>>name>>s;
            //string name(buf);
            score.push_back(make_pair(-s,name));
            dns[name]=s;
        }
        sort(score.begin(),score.end());
        // ¾_ð³ÌÉßµANðÂ¯é
        for(int i = 0; i < n; i++){
            score[i].first=score[i].first*(-1);
            ranks[score[i].second]=i+1;
        }
        vector<pair<int,string> > vpis;
        for(int i = 0; i < m; i++){
            string name;
            cin>>name;
            vpis.push_back(make_pair(ranks[name],name));
        }
        sort(vpis.begin(),vpis.end());
        for(int i = 0; i < m; i++){
            favs.push_back(vpis[i].second);
            favsRanks.push_back(ranks[vpis[i].second]);
            favsDns.push_back(dns[vpis[i].second]);
        }
        int ub=m;
        int lb=-1;
        while(ub-lb>1){
            int med=(ub+lb)/2;
            if(!check(med))
                ub=med;
            else
                lb=med;
        }
        if(check(ub))
            printf("%d\n",ub);
        else
            printf("%d\n",ub-1);
    }
}


int main(){

    solve();

    return 0;
}