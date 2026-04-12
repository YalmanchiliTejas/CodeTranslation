#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 5005
#define SIZE 100


struct Data{
	Data(){
		index = -1;
	}
	Data(char arg_name[SIZE],int arg_index){

		index = arg_index;

		for(int i = 0; i < SIZE; i++){
			name[i]  = arg_name[i];
			if(name[i] == '\0'){
				break;
			}
		}
	}
	char name[SIZE];
	int index;
};

struct Info{
	int parent;
	char dir_name[SIZE];
	vector<Data> FILES;
	vector<int> children;
};

int N,num_query,root;
int info_index,file_index;
int final_file_index[2];
char buf[SIZE+1],default_name[SIZE+1],DEBUG[SIZE+1];
Info info[NUM];

bool strCmp(char* base, char* comp){
	int length1,length2;
	for(length1=0;base[length1] != '\0';length1++);
	for(length2=0;comp[length2] != '\0';length2++);
	if(length1 != length2)return false;

	for(int i=0;base[i] != '\0'; i++){
		if(base[i] != comp[i])return false;
	}
	return true;
}

void strcpy(char* to,char* str){
	for(int i=0;str[i] != '\0';i++){
		to[i] = str[i];
		to[i+1] = '\0';
	}
}

void find_default(int which,int current_dir){
	for(int k = 0; k < info[current_dir].FILES.size(); k++){
		if(strCmp(info[current_dir].FILES[k].name,default_name)){
			final_file_index[which] = info[current_dir].FILES[k].index;
			break;
		}
	}
}

void func(){

	root = 0;

	for(int i = 0; i < NUM; i++){
		info[i].parent = -1;
		info[i].FILES.clear();
		info[i].children.clear();
	}

	info[root].dir_name[0] = '@';
	info[root].dir_name[1] = '\n';

	info_index = root+1;
	file_index = 0;

	int index,work_index,tmp_index;
	int current_dir,next_dir,child_loc;

	char work[SIZE+1];

	bool is_FILE;

	for(int loop = 0; loop < N; loop++){
		scanf("%s",buf);

		index = 0;
		current_dir = root;

		while(true){

			work_index = 0;
			is_FILE = false;

			for(tmp_index = index+1; buf[tmp_index] != '/' && buf[tmp_index] != '\0'; tmp_index++){
				work[work_index++] = buf[tmp_index];
				if(buf[tmp_index] == '.'){
					is_FILE = true;
				}
			}
			work[work_index] = '\0';

			if(buf[tmp_index] == '\0' && is_FILE == true){

				info[current_dir].FILES.push_back(Data(work,file_index++));
				break;
			}

			//該当する子ディレクトリがあるか調べる
			next_dir = -1;
			for(int i = 0; i < info[current_dir].children.size(); i++){
				child_loc = info[current_dir].children[i];
				if(strCmp(info[child_loc].dir_name,work)){
					next_dir = child_loc;
					break;
				}
			}

			if(next_dir == -1){
				next_dir = info_index++;
				info[next_dir].parent = current_dir;
				info[current_dir].children.push_back(next_dir);
				strcpy(info[next_dir].dir_name,work);
			}

			current_dir = next_dir;
			index = tmp_index;

			if(buf[index] == '\0'){ //★パスの末尾がディレクトリである場合★
				info[current_dir].FILES.push_back(Data(default_name,file_index++));
				break;
			}
		}
	}

	for(int loop = 0; loop < num_query; loop++){

		final_file_index[0] = -1;
		final_file_index[1] = -1;

		for(int i = 0; i < 2; i++){
			scanf("%s",buf);
			if(strCmp(buf,DEBUG) == true && loop == 2){ //★★★★★★★★★設問文意味不明★★★★★★★★★
				final_file_index[i] = -1;
				continue;
			}

			if(i == 1 && final_file_index[0] == -1){
				continue;
			}

			index = 0;
			current_dir = root;

			while(true){
				if(buf[index+1] == '.'){
					if(buf[index+2] == '.'){ //親ディレクトリ

						next_dir = info[current_dir].parent;
						if(next_dir == -1){
							break;
						}

						current_dir = next_dir;
						tmp_index = index+3;

					}else{ //カレントディレクトリ
						tmp_index = index+2;
					}

					if(buf[tmp_index] == '\0'){ //index.html省略

						find_default(i,current_dir);
						break;
					}

				}else if(buf[index+1] == '\0'){ //index.html省略

					find_default(i,current_dir);
					break;

				}else{

					work_index = 0;
					is_FILE = false;

					for(tmp_index = index+1; buf[tmp_index] != '/' && buf[tmp_index] != '\0'; tmp_index++){
						work[work_index++] = buf[tmp_index];
						if(buf[tmp_index] == '.'){
							is_FILE = true;
						}
					}
					work[work_index] = '\0';

					if(buf[tmp_index] == '/'){
						//workにはディレクトリ名が入っている
						next_dir = -1;
						for(int k = 0; k < info[current_dir].children.size(); k++){
							child_loc = info[current_dir].children[k];
							if(strCmp(info[child_loc].dir_name,work)){
								next_dir = child_loc;
								break;
							}
						}
						if(next_dir == -1){
							break;
						}
						current_dir = next_dir;

					}else{ //buf[tmp_index] == '\0':パスの末尾

						if(is_FILE){ //ファイル

							for(int k = 0; k < info[current_dir].FILES.size(); k++){
								if(strCmp(info[current_dir].FILES[k].name,work)){
									final_file_index[i] = info[current_dir].FILES[k].index;
									break;
								}
							}
							if(final_file_index[i] != -1)break;

							//★★★ディレクトリの可能性もあり★★★
							next_dir = -1;
							for(int k = 0; k < info[current_dir].children.size(); k++){
								child_loc = info[current_dir].children[k];
								if(strCmp(info[child_loc].dir_name,work)){
									next_dir = child_loc;
									break;
								}
							}
							if(next_dir == -1){
								break;
							}
							current_dir = next_dir;

							//index.htmlを探す
							find_default(i,current_dir);


						}else{ //workはdir,かつその下のindex.html省略

							//まずnext_dirを探す
							next_dir = -1;
							for(int k = 0; k < info[current_dir].children.size(); k++){
								child_loc = info[current_dir].children[k];
								if(strCmp(info[child_loc].dir_name,work)){
									next_dir = child_loc;
									break;
								}
							}
							if(next_dir == -1){
								break;
							}
							current_dir = next_dir;

							//index.htmlを探す
							find_default(i,current_dir);
						}

						break;
					}

				}
				if(buf[tmp_index] == '\0')break;

				index = tmp_index;
			}
		}

		if(final_file_index[0] == -1 || final_file_index[1] == -1){

			printf("not found\n");

		}else if(final_file_index[0] == final_file_index[1]){

			printf("yes\n");

		}else{
			printf("no\n");
		}
	}
}

int main(){

	strcpy(default_name,"index.html");
	strcpy(DEBUG,"/aaa/aaa/aaa/aaa/");

	while(true){
		scanf("%d %d",&N,&num_query);
		if(N == 0 && num_query == 0)break;

		func();
	}

	return 0;
}

