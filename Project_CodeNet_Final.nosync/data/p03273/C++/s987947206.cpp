#include<iostream>
#include<vector>

int main(){
	//入力機構
	size_t H,W;
	std::cin>>H>>W;
	std::vector<std::vector<char>> a(H,std::vector<char>(W,0));
	for(size_t i=0;i<H;i++){
		for(size_t j=0;j<W;j++){
			std::cin>>a[i][j];
		}
	}

	//処理機構
	//ある列が全て白であるなら、他の列・行を消してもその列は消せる。行についても同様。
	//また、ある列のいずれかの要素が白でない場合は、黒のマスを消す操作は不可能なので、その列は消せない。行についても同様。
	//つまり、列・行において、全ての要素が白であるものを探し、それを無視して行列を出力すればよい。
	std::vector<bool> rowFlag(W,false),columnFlag(H,false);//その行・列は無視せず出力するかどうか
	//rowFlag,columnFlagの計算
	for(size_t x=0;x<W;x++){
		for(size_t y=0;y<H;y++){
			if(a[y][x]=='#'){
				//1つでも黒があれば、その列は出力
				rowFlag[x]=true;
				break;
			}
		}
	}
	for(size_t y=0;y<H;y++){
		for(size_t x=0;x<W;x++){
			if(a[y][x]=='#'){
				//1つでも黒があれば、その行は出力
				columnFlag[y]=true;
				break;
			}
		}
	}

	//出力機構
	for(size_t y=0;y<H;y++){
		if(columnFlag[y]){
			for(size_t x=0;x<W;x++){
				if(rowFlag[x]){
					std::cout<<a[y][x];
				}
			}
			std::cout<<std::endl;
		}
	}

	return 0;
}