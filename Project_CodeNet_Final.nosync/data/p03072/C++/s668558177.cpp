#include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    int H[N];
    for(int i=0; i<N; i++)
        scanf("%d", &H[i]);
    
    int max_height = H[0];
    int count = 1;
    for(int i=1; i<N; i++){
        if(H[i] >= max_height){
            count++;
            max_height = H[i];
        }
    }
    printf("%d\n", count);
    return 0;
}
