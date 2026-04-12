#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
using namespace std;

//////全探索したいときに開けよ////////
/*
vector<vector<int>> fspattern;
vector<int> fspattern_draft;
int fspcnt = 0;

void setfspattern_core(int floor,int number,int degree){
  if(floor==degree){
    fspattern.at(fspcnt) = fspattern_draft;
    fspcnt++;
  }else{
    rep(i,number){
      fspattern_draft.at(floor) = i;
      setfspattern_core(floor+1,number,degree);
    }
  }
}

void setfspattern(int number,int degree){
  int64_t array_num = 1;
  rep(i,degree){
    array_num *= number;
  }
  fspattern = vector<vector<int>>(array_num,vector<int>(degree));
  fspattern_draft = vector<int>(degree);
  setfspattern_core(0,number,degree);
}
*/

//////nCrのmodを求めたいときに開けよ/////////
//int64_t univMod = 1000000007;
//int64_t factnum = 100000
//vector<int64_t> modfact(factnum);
//vector<int64_t> modinvfact(factnum);

/*void setmodfact(){
  for(int i=0;i<factnum;i++){
    if(i == 0){
      modfact.at(i) = 1;
    }else{
      modfact.at(i) = (modfact.at(i-1)*i)%univMod;
    }
  }
}

int64_t calcmodpower(int64_t a,int64_t n){
  int64_t res = 1;
  while(n != 0){
    if(n & 1){
      res = (res * a) % univMod;
    }
    a = (a*a) % univMod;
    n = n >> 1;
  }
  return res;
}

int64_t calcinverse(int64_t n){
	return calcmodpower(n,univMod-2);
}

void setmodinvfact(){
  for(int i=0;i<factnum;i++){
    if(i==0){
      modinvfact.at(i) = 1;
    }else{
      modinvfact.at(i) = calcmodpower(modfact.at(i),univMod-2);
    }
  }
}*/


/*
int64_t calcGCD(int64_t a,int64_t b){
	int64_t p = a;
	int64_t q = b;
	int64_t c = a%b;
	while(c != 0){
		p = q;
		q = c;
		c = p%q;
	}
	return q;
}
*/
vector<int64_t> pat(51);
vector<int64_t> true_pat(51);
int64_t saiki(int64_t n,int64_t x){
  if(x == 0){
    return 0;
  }else if(n==0){
    return 1;
  }else{
    if(x == 1){
      return 0;
    }else if(x <= pat.at(n-1)+1){
      return saiki(n-1,x-1);
    }else if(x == pat.at(n-1)+2){
      return saiki(n-1,x-1)+1;
    }else if (x <= 2*pat.at(n-1)+2){
      return true_pat.at(n-1)+saiki(n-1,x-pat.at(n-1)-2)+1;
    }else{
      return true_pat.at(n-1)+saiki(n-1,x-pat.at(n-1)-2)+1;
    }
  }
}
  
int main(){
  int64_t n,x;
  cin >> n >> x;
  pat.at(0) = 1;
  for(int i=1;i<=50;i++){
    pat.at(i) = 2*pat.at(i-1)+3;
    //cout << pat.at(i) <<",";
  }
  //cout << endl;
  true_pat.at(0) = 1;
  for(int i=1;i<=50;i++){
    true_pat.at(i) = 2*true_pat.at(i-1)+1;
    //cout << true_pat.at(i) <<",";
  }
  //cout << endl;
  cout << saiki(n,x);
}