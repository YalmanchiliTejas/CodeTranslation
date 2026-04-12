#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
int main()
{
	LL N,X,M;
	LL S=0;
	cin>>N>>X>>M;
	LL i;
	LL A=X;
	S+=A;
	set<LL> mySet;
	set<LL>::iterator sit;
	mySet.insert(A);
	bool bClear=false;
	LL firstA=0;
	for (i=2;i<=N;i++){
		A=(A*A)%M;
		sit=mySet.find(A);
		if (sit==mySet.end()){
			mySet.insert(A);
		}else{
			if (!bClear){
				mySet.clear();
				mySet.insert(A);
				firstA=A;
				bClear=true;
			}else{
				break;
			}
		}
		if (A==0){
			cout<<S<<endl;
			return 0;
		}	
		S+=A;
	}
	LL mySetNums=mySet.size();
	if (i<N && mySetNums>0){
		LL remain=N-i;
		LL nums=remain/mySetNums;
		i=N-remain%mySetNums;
		LL S1=0;
		for (sit=mySet.begin();sit!=mySet.end();sit++){
			S1+=(*sit);
		}
		S+=S1*nums;
		A=firstA;
		S+=A;
		i++;
	}
	for (;i<=N;i++){
		A=(A*A)%M;
		S+=A;
	}
	cout<<S<<endl;
	return 0;
}