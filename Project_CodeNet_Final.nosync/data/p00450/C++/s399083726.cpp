#include<stdio.h>
int d[100000],s[100000];
int i,j;
int n,m;
int ans;

void set(int i,int m){
	if(m==1){
		if(d[i-1]<0){
			d[i]=d[i-1]-1;
			s[i]=s[i-1];
		}
		else{
			d[i]=-1;
			s[i]=i;
		}
	}
	if(m==0){
		if(d[i-1]>0){
			d[i]=d[i-1]+1;
			s[i]=s[i-1];
		}
		else{
			d[i]=1;
			s[i]=i;
		}
		ans++;
	}
}


int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)return 0;
		ans=0;
		for(i=0;i<n;i++){
			d[i]=0;
			s[i]=0;
		}
		for(i=0;i<n;i++){
			scanf("%d",&m);
			if(i==0){
				if(m==0){
					d[i]=1;
					ans++;
				}
				else d[i]=-1;
				s[0]=0;
				continue;
			}
			if(i%2==0)set(i,m);
			else{
				if(m==1&&d[i-1]<0){
					d[i]=d[i-1]-1;
					s[i]=s[i-1];
				}
				if(m==0&&d[i-1]>0){
					d[i]=d[i-1]+1;
					s[i]=s[i-1];
					ans++;
				}
				if(m==1&&d[i-1]>0){
					if(s[i-1]>0){
						if(d[s[i-1]-1]>0){
							d[i]=-d[i-1]-d[s[i-1]-1]-1;
							s[i]=s[s[i-1]-1];
							ans-=d[i-1]+d[s[i-1]-1];
						}
						else{
							d[i]=-d[i-1]+d[s[i-1]-1]-1;
							s[i]=s[s[i-1]-1];
							ans-=d[i-1];
						}
					}
					else{
						d[i]=-d[i-1]-1;
						s[i]=0;
						ans-=d[i-1];
					}
				}
				if(m==0&&d[i-1]<0){
					if(s[i-1]>0){
						if(d[s[i-1]-1]<0){
							d[i]=-d[i-1]-d[s[i-1]-1]+1;
							s[i]=s[s[i-1]-1];
							ans+=d[i];
						}
						else{
							d[i]=-d[i-1]+d[s[i-1]-1]+1;
							s[i]=s[s[i-1]-1];
							ans+=-d[i-1]+1;
						}
					}
					else{
						d[i]=-d[i-1]+1;
						s[i]=0;
						ans+=d[i];
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}