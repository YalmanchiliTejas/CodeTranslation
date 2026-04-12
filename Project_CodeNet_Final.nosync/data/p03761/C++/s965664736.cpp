#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	int n;
	cin>>n;

	vector<string>vstr(n);
	for(auto& e:vstr)cin>>e;
    
    vector<int>a(26);
    for(int j=0;j<vstr[0].size();++j){
        ++a[vstr[0][j]-'a'];
    }
    for(int i=1;i<n;++i){
        vector<int>a_(26,0);
        for(int j=0;j<vstr[i].size();++j){
            ++a_[vstr[i][j]-'a'];
        }
        for(int j=0;j<a.size();++j){
            if(a_[j]!=0&&a[j]!=0)a[j]=min(a_[j],a[j]);
            else a[j]=0;
        }
    }
    
    string ans="";
    for(int i=0;i<a.size();++i)
        for(int j=0;j<a[i];++j)
            ans+='a'+i;
    
    cout<<ans<<endl;

	return 0;
}
