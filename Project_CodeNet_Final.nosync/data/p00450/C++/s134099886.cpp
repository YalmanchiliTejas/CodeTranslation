#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int>T;
typedef vector<T>VT;
int main(void){
	int n;
	int stone[100001];
	int i,j,k;
	int f,b,c;
	VT v;
	int sum;
	while(1){
		cin>>n;
		v.clear();
		if(n==0)	break;
		for(i=1;i<=n;i++)	cin>>stone[i];
		f=1;	b=1;	c=stone[i];
		v.push_back(make_tuple(f,b,c));
		for(i=2;i<=n;i++){
			if(i%2!=0){
				if(stone[i]!=stone[i-1]){
					f=i;	b=i;	c=stone[i];
					v.push_back(make_tuple(f,b,c));
				}
				else{
					get<1>(v[v.size()-1])++;
				}
			}
			else{//i%2==0
				if(stone[i]==stone[i-1]){
					get<1>(v[v.size()-1])++;
				}
				else{//stone[i]!=stone[i-1]
					v.push_back(make_tuple(i,i,stone[i]));
					/* for(j=0;j<v.size();j++)		cout<<get<0>(v[j])<<" "<<get<1>(v[j])<<" "<<get<2>(v[j])<<endl;
					cout<<endl; */
					j=v.size()-1;
					//cout<<j<<endl;
					while(j>-1){
						j--;
						if(stone[i]==get<2>(v[j]))	break;
					}
					//cout<<j<<endl;
					if(j==-1){
						v.clear();
						f=1;	b=i;	c=stone[i];
						v.push_back(make_tuple(f,b,c));
					}
					else{
						get<0>(v[v.size()-1])=get<0>(v[j]);
						for(k=v.size()-2;k>=j;k--){
							v.erase(v.begin()+k);
						}
					}
					/* for(j=0;j<v.size();j++)		cout<<get<0>(v[j])<<" "<<get<1>(v[j])<<" "<<get<2>(v[j])<<endl;
					cout<<endl; */
				}
			}
			/* for(j=0;j<v.size();j++)		cout<<get<0>(v[j])<<" "<<get<1>(v[j])<<" "<<get<2>(v[j])<<endl;
			cout<<endl; */
		}
		sum=0;
		for(i=0;i<v.size();i++){
			if(get<2>(v[i])==0){
				//cout<<get<1>(v[i])-(get<0>(v[i])-1)<<endl;
				sum+=get<1>(v[i])-(get<0>(v[i])-1);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
				
				
			
		
	
