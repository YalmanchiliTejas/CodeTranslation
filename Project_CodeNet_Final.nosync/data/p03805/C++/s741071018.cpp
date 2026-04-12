#include<iostream>
#include<set>
using namespace std;
int n,m;
int startPoint[28];
int endPoints[28];
int result=0;

/**判断是否所有点都遍历过,passPoint表示已经遍历过的点*/
bool allPassed(set<int> passPoint){
	for(int i =1;i<=n;i++){
		//从1到n，只要有一个在passPoint 里面不存在，说明没有都遍历过 
		if(passPoint.count(i)==0){
			return 0;
		}
	}
	return 1;
}

void printSet(set<int> s){
	set<int>::iterator iter = s.begin();
	while (iter!=s.end()){
		cout<<*iter<<"\t";
		iter++;
	}
	cout<<endl;
}
/**
往前走一步，current表示当前节点
passPoint 表示已经遍历过的点
passEdge 表示已经遍历过的边 
*/
void goOneStep(int current,set<int> passPoint,set<int>  passEdge){
	/**每走一步，需要判断当前这个点有哪些下一步可以走
		但是已经遍历过的点不能再走了
		已经用过的边，不能再走了
		往前走一步，把走过的点和边记录下来
		如果判断所有的点走过，那么就可以返回，并且结果+1
		如果没有边可以走，那么也返回，但是结果不+1 
	*/
	if(allPassed(passPoint)) {
		result ++;
		//cout << "success!\n";
		return ;
	}
	
	for(int i=0;i<m;i++){
		int next;
		if(passEdge.count(i)>0){
			//走过的边不能再走了 
			continue;
		}
		//如果开始节点和当前节点一致，那么下一步就是结束节点
		//如果结束节点和当前节点一致，那么下一步就是开始节点
		//如果都不一致，就和不在候选之列 
		if(startPoint[i]==current ){
			next=endPoints[i];
		}else if(endPoints[i] == current){
			next = startPoint[i];
		}else{
			continue;
		}
		if(passPoint.count(next)>0){
			//走过的点不能走 
			continue;
		}
		set<int> thisPassPoint =  passPoint;
		thisPassPoint.insert(next);
		set<int> thisPassEdge = passEdge;
		thisPassEdge.insert(i);
		//cout<<"from:"<<current<<"to"<<next<<endl;
		/**
		cout<<"passPoint:";
		printSet(thisPassPoint);
		cout<<"passEdge:";
		printSet(thisPassEdge);
		*/
		goOneStep(next,thisPassPoint,thisPassEdge);
	}
	
}



int main(){
	set<int> passPoint,passEdge;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin >> startPoint[i] >> endPoints[i];
	}
	passPoint.insert(1);
	goOneStep(1,passPoint,passEdge);
	cout<<result;
}