#include <iostream>
#include <string>

using namespace std;
	
	
class Hoge{
			int N;
			int* pyama;
			int imax,imaxn;
			int iryokann;
			
		public:
			Hoge(int hoge){
			
			pyama=new int[100];
			imax=0;
			iryokann=0;
			
			}
			
			
		void input();
		void checkmax();			
		
		
	int getiryokann(){return iryokann;}

			

									
		virtual ~Hoge(){	
					delete[] pyama;
					//cout<<"pyama is erased."<<endl;
						}
};



void Hoge::input(){
		
					cin>>N;
					for (int icount=0;icount<N;icount++)
					cin>>pyama[icount];
					}
					
					
void Hoge::checkmax(){
	
				for (int icount=0;icount<N;icount++){
					
							if(pyama[icount]>=imax){
							
													imaxn=icount;
													imax=pyama[icount];
													iryokann++;
							}
									
									
								}//end for
						}//end function

int main()
{
	int iryokann;
	Hoge* ph0=new Hoge(0);
	ph0->input();
	ph0->checkmax();
	iryokann=ph0->getiryokann();
	cout<<iryokann<<endl;
	delete ph0;
	
}