#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int H, W;

    scanf("%d %d", &H, &W);
    
    vector<vector<char>> T(H, vector<char>(W));
    int i, j;
    char dummy;

    for ( i = 0; i < H; i++ ) {
        scanf("%c", &dummy);

        for (j = 0; j < W; j++ ){
            scanf("%c", &T.at(i).at(j));
        }
    }

    /*
    for ( i = 0; i < H; i++ ) {
        for (j = 0; j < W; j++ ){
            printf("%c", T.at(i).at(j));

            if ( j == W-1 ){
                printf("\n");
            }
        }
    }
    */
   
    int Hr=0, Wr=0;
    bool rm;

    for ( i = 0; i < H; i++ ) {
        rm = true; // when array most be removed, rm = false.  

        for ( j = 0; j < W; j++ ) {
            if ( T.at(i).at(j) == '#')
            break;

            if ( j == W - 1 )
            rm = false;
        }

        if ( rm ) {
            for ( j = 0; j < W; j++ ) {
                T.at(Hr).at(j) = T.at(i).at(j);
            }
            Hr++;
        }
    }

     for ( j = 0; j < W; j++ ) {
        rm = true; 

        for ( i = 0; i < Hr; i++ ) {
            if ( T.at(i).at(j) == '#')
            break;

            if ( i == Hr - 1 )
            rm = false;
        }

        if ( rm ) {
            for ( i = 0; i < Hr; i++ ) {
                T.at(i).at(Wr) = T.at(i).at(j);
            }
            Wr++;
        }
    }   

    for ( i = 0; i < Hr; i++ ) {
        for (j = 0; j < Wr; j++ ){
            printf("%c", T.at(i).at(j));

            if ( j == Wr - 1 ){
                printf("\n");
            }
        }
    }


    return 0;
}