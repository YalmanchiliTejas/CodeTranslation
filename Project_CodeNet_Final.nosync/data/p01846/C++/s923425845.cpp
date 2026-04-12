#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

vector<vector<int>> makem(string s){
    vector<string> ss;
    string t="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='/'){
            ss.push_back(t);
            t="";
            continue;
        }
        t+=s[i];
    }
    ss.push_back(t);
    int w=0;
    for(int i=0;i<ss[0].size();i++){
        if(ss[0][i]=='b'){
            w++;
        }else{
            w+=ss[0][i]-'0';
        }
    }
    int h=ss.size();
    vector<vector<int>> m(h,vector<int>(w,0));
    for(int i=0;i<h;i++){
        int mid=0;
        int sid=0;
        while(mid<w){
            if(ss[i][sid]=='b'){
                m[i][mid]=1;
                mid++;
            }else{
                mid+=ss[i][sid]-'0';
            }
            sid++;
        }
    }
    return m;
}

string enco(vector<vector<int>> m){
    vector<string> row(m.size(),"");
    for(int i=0;i<m.size();i++){
        int cnt=0;
        for(int j=0;j<m[i].size();j++){
            if(m[i][j]==0){
                cnt++;
            }else{
                if(cnt!=0){
                    row[i]+=to_string(cnt);
                    cnt=0;
                }
                row[i]+="b";
            }
            if(j==(int)m[i].size()-1&&cnt!=0){
                row[i]+=to_string(cnt);
            }
        }
    }
    string ans="";
    for(int i=0;i<(int)m.size()-1;i++){
        ans+=row[i]+"/";
    }ans+=row.back();
    return ans;
}

int main(){

    while(1){
        string s;
        cin >> s;
        if(s=="#")break;
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        vector<vector<int>> m;
        m=makem(s);
        m[a][b]=0;
        m[c][d]=1;
        string ans=enco(m);
        cout << ans << endl;
    }

    return 0;
}
