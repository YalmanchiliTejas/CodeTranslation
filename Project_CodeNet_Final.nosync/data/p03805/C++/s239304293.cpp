#include<iostream>

#define MAX 8

typedef struct{
	int root[MAX-1];
	int mem_of_root;
	bool use;
}POINT;
using namespace std;

void process(POINT point[], int n, int pos, int *ans);
bool check(POINT point[], int n);
int main(){
	POINT point[MAX];
	int i;
	int n,m;
	int a,b;
	int pos;
	int ans = 0;
	for(i=0; i<MAX;i++){
		point[i].mem_of_root = 0;
		point[i].use = false;
	}
	cin >> n >> m;
	
	for(i=0;i<m;i++){
		cin >> a >> b;
		point[a-1].root[point[a-1].mem_of_root++] = b - 1;
		point[b-1].root[point[b-1].mem_of_root++] = a - 1;
	}
 	process(point,n,0,&ans);
 	cout << ans << endl;
}
void process(POINT point[], int n, int pos, int *ans){
	int i;
	if( point[pos].use == true )
		return;
	point[pos].use = true;
	if( check(point,n) ){
		*ans = *ans + 1;
		point[pos].use = false;
		return;
	}
	for(i=0;i<point[pos].mem_of_root;i++){
		process(point,n,point[pos].root[i],ans);
	}
	point[pos].use = false;
	return;
}
bool check(POINT point[], int n){
	int i;
	
	for(i=0; i<n;i++){
		if( point[i].use == false)
			return false;
	}
	
	return true;
}