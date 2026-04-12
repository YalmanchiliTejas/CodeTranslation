#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
char in[110];
string url[110];
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		for(int i=0;i<a;i++){
			scanf("%s",in);
			url[i]=in;
		}
		while(b--){
			string A,B;
			scanf("%s",in);A=in;
			scanf("%s",in);B=in;
			string now="";
			int Aat=0;
			int Bat=0;
			for(int i=0;i<A.size();i++){
				if(i+1<A.size()&&A[i]=='.'&&A[i+1]=='.'){
					if(now.size()<=1){
						Aat=-1;break;
					}
					now.erase(now.size()-1);
					while(now[now.size()-1]!='/')now.erase(now.size()-1);
					i+=2;continue;
				}else if(i&&A[i-1]=='/'&&A[i]=='.'){
					i+=1;continue;
				}
				now+=A[i];
				bool ok=false;
				for(int j=0;j<a;j++)if(now.size()<=url[j].size()&&url[j].substr(0,now.size())==now){
					ok=true;break;
				}
				if(!ok){Aat=-1;break;}
			}
	//		printf("%s %d\n",now.c_str(),Aat);
			if(!~Aat){printf("not found\n");continue;}
			Aat=-1;
			for(int i=0;i<a;i++){
				if(now.size()<=url[i].size()&&url[i].substr(0,now.size())==now){
					if(now==url[i]||(now[now.size()-1]=='/'&&now+"index.html"==url[i])||
					(now+"/index.html"==url[i])){Aat=i;break;}
				}
			}
			if(!~Aat){printf("not found\n");continue;}
			now="";
			for(int i=0;i<B.size();i++){
				if(i+1<B.size()&&B[i]=='.'&&B[i+1]=='.'){
					if(now.size()<=1){
						Bat=-1;break;
					}
					now.erase(now.size()-1);
					while(now[now.size()-1]!='/')now.erase(now.size()-1);
					i+=2;continue;
				}else if(i&B[i-1]=='/'&&B[i]=='.'){
					i+=1;continue;
				}
				now+=B[i];
				bool ok=false;
				for(int j=0;j<a;j++)if(now.size()<=url[j].size()&&url[j].substr(0,now.size())==now){
					ok=true;break;
				}
				if(!ok){Bat=-1;break;}
			}
		//	printf("%s %d\n",now.c_str(),Bat);
			if(!~Bat){printf("not found\n");continue;}
			Bat=-1;
			for(int i=0;i<a;i++){
				if(now.size()<=url[i].size()&&url[i].substr(0,now.size())==now){
					if(now==url[i]||(now[now.size()-1]=='/'&&now+"index.html"==url[i])||(now+"/index.html"==url[i])){Bat=i;break;}
				}
			}
			if(!~Bat){printf("not found\n");continue;}
			if(Aat==Bat)printf("yes\n");
			else printf("no\n");
		}
	}
}