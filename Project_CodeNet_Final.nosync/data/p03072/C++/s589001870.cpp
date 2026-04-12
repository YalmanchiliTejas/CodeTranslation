#include<cstdio>
#include <array>

int main()
{
        int N;
        std::array < int , 20 > H{};
        int ans = 0;
        scanf("%d",&N);
        for ( int i = 0; i<N ;i++ ){
                        scanf("%d",&H[i]);
        }
        for ( int i = 0; i < N ; i++ )
        {
                for  (int j = 0; j < i+1; j++ ){
                        if ( i == j ){
                                        ans +=1;
                        }
                        if (    H[j] > H[i]  ){
                                        break;
                        }

                }
        }
        printf("%d\n", ans);
                return 0;
}