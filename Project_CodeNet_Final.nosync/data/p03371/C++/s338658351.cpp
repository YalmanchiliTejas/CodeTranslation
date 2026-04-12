

#include <cstdio>

int main(int argc, const char * argv[]) {
    
    
    int a,b,c,x,y;
    
    scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    
    if(a+b>2*c){//c를 먼저 다사
        
        if(x>y){ //추가로 a피자
            int sum = 2*c*y;
            
            if(a<2*c){
                sum+=a*(x-y);
            }else{
                sum+=2*c*(x-y);
            }
            printf("%d\n",sum);
        }else{//추가로 b피자
            //
            int sum = 2*c*x;
            
            if(b<2*c){
                sum+=b*(y-x);
            }
            else{
                sum+=2*c*(y-x);
            }
            
            printf("%d\n",sum);
        }
    }else{
        printf("%d\n",a*x+b*y);
    }
    
    return 0;
}
