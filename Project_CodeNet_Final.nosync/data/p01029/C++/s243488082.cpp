#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

struct Node{

	char ch;
	vector<int> ADJ;
};

int V,E;
bool check[26];
char buf[2];
Node nodes[NUM];


int main(){

	scanf("%d %d",&V,&E);

	for(int i = 0; i < V; i++){

		scanf("%s",buf);
		nodes[i].ch = buf[0];
	}

	int from,to;

	for(int loop = 0; loop < E; loop++){

		scanf("%d %d",&from,&to);
		nodes[from].ADJ.push_back(to);
		nodes[to].ADJ.push_back(from);
	}

	for(int i = 0; i < V; i++){

		if(nodes[i].ch != '?'){

			printf("%c",nodes[i].ch);

		}else{

			for(int k = 0; k < 26; k++){

				check[k] = false;
			}

			for(int k = 0; k < nodes[i].ADJ.size(); k++){

				if(nodes[nodes[i].ADJ[k]].ch != '?'){

					check[nodes[nodes[i].ADJ[k]].ch-'a'] = true;
				}
			}

			for(int k = 0; k < 26; k++){

				if(!check[k]){
					nodes[i].ch = 'a'+k;
					printf("%c",nodes[i].ch);
					break;
				}
			}
		}
	}

	printf("\n");

	return 0;
}

