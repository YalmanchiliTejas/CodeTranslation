#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
  map<char,bool> a;
  a['q']=a['w']=a['e']=a['r']=a['t']=a['a']=a['s']=a['d']=a['f']=a['g']=a['z']=a['x']=a['c']=a['v']=a['b']=true;
  a['y']=a['u']=a['i']=a['o']=a['p']=a['h']=a['j']=a['k']=a['l']=a['n']=a['m']=false;
  char str[35];
  while(1){
    scanf("%s",str);
    if(strcmp(str,"#")==0) break;
    int l=strlen(str),cnt=0;
    bool dotti=a[str[0]];
    for(int i=1;i<l;i++){
      if(dotti!=a[str[i]]){
	dotti=a[str[i]];
	cnt++;
      }
    }
    cout << cnt << endl;
  }
}