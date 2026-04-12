#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int l;
	cin>>l;
	char a[100][1000];
	vector<char> ans;

	int n[100]={};
	string b;
	char d;
	int c,e;

	while(1){
	cin>>b;
		

	

		if(b=="push"){
			
			cin>>c>>d;
			a[c][n[c]]=d;
			n[c]+=1;
		}
		
		if(b=="pop"){
			cin>>c;
			//cout << a[c][n[c]] << endl;
			//cout << n[c] << endl;
			ans.push_back(a[c][n[c]-1]);
			n[c]-=1;
		}	

		if(b=="move"){
			cin>>c>>e;
			a[e][n[e]]=a[c][n[c]-1];
			n[e]+=1;
			n[c]-=1;
		}		
	
		if(b=="quit")break;
	
	}

	for(int i=0;i<ans.size();i++){	
	cout<<ans[i]<<endl;
	}

    return 0;
}