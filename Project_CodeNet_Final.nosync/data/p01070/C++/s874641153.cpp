#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int T_length,P_length,range;
int *Rank; //接尾辞文字列の開始位置iの、辞書順にsortした際の順位表
int *Suffix_Array; //接尾辞文字列の開始位置<インデックス>→毎回、辞書順に開始位置をソートする
int *Work; //作業用配列

char T[100001],P[100001];


//Tのstart文字目から、P_length文字分、Pと比較
//0:等しい 1:Pの方が辞書順で早い 2:Tの方が辞書順で早い
int strCmp_Suffix_Array(int start){
	int index,ret;

	ret = 0;

	for(index = 0; index < P_length && T[start+index] != '\0'; index++){
		if(P[index] != T[start+index]){
			if(P[index] > T[start+index]){ //Tの方が辞書順で早い
				ret = 2;
			}else{
				ret = 1;
			}
			break;
		}
	}
	if(ret == 0 && index < P_length){ //不一致がないまま、Tが先に終わった場合
		ret = 2; //Tの方が辞書順で早い
	}
	return ret;
}


//まずrank[a]とrank[b]を比較、等しければrank[a+range],rank[b+range]を比較
bool compare_Suffix_Array(int a,int b){
	if(Rank[a] != Rank[b])return Rank[a] < Rank[b];
	else{
		int rank_a = a + range <= T_length ? Rank[a+range]:-1; //rangeを足した部分が範囲外なら、最高にするため、rankを-1にする
		int rank_b = b + range <= T_length ? Rank[b+range]:-1;
		return rank_a < rank_b;
	}
}

//文字列Tの接尾辞配列を構築
void make_Suffix_Array(){
	for(int i = 0; i <= T_length; i++){
		Suffix_Array[i] = i;
		Rank[i] = i < T_length? T[i]:-1; //初期ランクは文字コードにする。T[T_length]は空文字なので、最高となるように-1とする
	}

	//range,2*range,4*range,とソート幅を次第に伸ばしていく
	for(range = 1; range <= T_length; range*=2){
		sort(Suffix_Array,Suffix_Array+(T_length+1),compare_Suffix_Array); //range文字の幅でsuffix_Arrayをソート

		Work[Suffix_Array[0]] = 0;
		for(int i = 1; i <= T_length; i++){
			Work[Suffix_Array[i]] = Work[Suffix_Array[i-1]] + (compare_Suffix_Array(Suffix_Array[i-1],Suffix_Array[i])?1:0);
		}
		for(int i = 0; i <= T_length; i++){
			Rank[i] = Work[i];
		}
	}
}


//パターン文字列の、Suffix_Array上での、最も左の一致★インデックス★を返却
int find_match_left(){

	int ret = BIG_NUM;

	int left = 0,right = T_length,m;
	m = (left+right)/2; //suffix_arrayのインデックス

	while(left <= right){
		switch(strCmp_Suffix_Array(Suffix_Array[m])){
		case 0: //T[Suffix_Array[m]～Suffix_Array[m]+P_length]の部分文字列がPと等しい
			ret = m;
			right = m-1; //より左へ
			break;
		case 1: //Pの方が辞書順で早い
			right = m-1;
			break;
		case 2: //Tの方が辞書順で早い
			left = m+1;
			break;
		}
		m = (left+right)/2;
	}
	return ret;
}

//パターン文字列の、Suffix_Array上での、最も右の一致★インデックス★を返却
int find_match_right(){

	int ret = -1;

	int left = 0,right = T_length,m;
	m = (left+right)/2; //suffix_arrayのインデックス

	while(left <= right){
		switch(strCmp_Suffix_Array(Suffix_Array[m])){
		case 0: //T[Suffix_Array[m]～Suffix_Array[m]+P_length]の部分文字列がPと等しい
			ret = max(ret,m);
			left = m+1; //より右へ
			break;
		case 1: //Pの方が辞書順で早い
			right = m-1;
			break;
		case 2: //Tの方が辞書順で早い
			left = m+1;
			break;
		}
		m = (left+right)/2;
	}
	return ret;
}

int count_contain(int left,int right){

	//一番左の一致箇所
	int match_left = find_match_left();
	if(match_left == BIG_NUM)return 0;

	//一番右の一致箇所
	int match_right = find_match_right();
	if(match_right == BIG_NUM)return 0;

	int ret = 0;
	for(int i = match_left; i <= match_right; i++){
		if(Suffix_Array[i] >= left && Suffix_Array[i]+P_length-1 <= right)ret++;
	}
	return ret;
}


int main(){

	int num_query;
	scanf("%s %d",T,&num_query);

	for(T_length = 0; T[T_length] != '\0'; T_length++);

	Rank = new int[T_length+1];
	Suffix_Array = new int[T_length+1];
	Work = new int[T_length+1];

	make_Suffix_Array();

	int left,right;

	for(int loop = 0; loop < num_query; loop++){
		scanf("%d %d %s",&left,&right,P);

		for(P_length = 0; P[P_length] != '\0'; P_length++);

		printf("%d\n",count_contain(left,right));
	}

	return 0;
}

