#include <iostream>

using namespace std;

int main(){
    /*
    statement:
        if and only if the number of # is equal to H + W - 1, the answer is Possible.
    Proof:
        let the matrix 'a', a representation of a two-dimensional coordinate.

        each left move subtracts one to the stone's X
        each up move subtracts one to the stone's Y
        each right move adds one to the stone's X
        each down move subtracts one to the stone's Y

        so if Shik moves only right or down, it can only increase X or Y value by one.
        so Shik can't be in any place more than once.

        at the end, Shik's X has increased by H - 1
        so (he or she) should make at least H - 1 right moves
        at the end, Shik's Y has increased by W - 1
        so (he or she) should make at least W - 1 down moves

        therefore, Shik has made at least H + W - 2 moves.
        so number of #s can't be less than H + W - 2.


        lets assume that a # exists, that doesnt have any neighbouring right or down #(and it is not the Shiks destination)
        the next move after arriving was up or left. so the answer is impossible.
        therefore, each # has *at least* one neighbouring rigth or down #.

        lets assume that a # exists, that has both right and down neighbouring #.(and it is not the Shiks destination)
        the next move after arriving can be right or down.
        if the Shik goes right, (he or she) can never decrease (him or her) X to Visit that coordinate again, without at least one left move.
        for the same reason, the answer is impossible if Shik chooses down.
        its obvious that if Shik's next move is up or left, the answer is impossible either.
        therefore, each # has *exactly* one neighbouring rigth or down #.

        because Shik can't be in a place more than once and has to be there at least one, each # represents a move to it; and vice versa(except the a[1,1]).
        we now know that Shik should make exactly H - 1 down moves and W - 1 rigth moves.
        so we have exactly H - 1 + W - 1 #s, except the a[1,1]. in total, we have exactly H + W - 1 #.

        so the answer is possible, only with H + W - 1 #s.

        if the route form 1,1 and H,W exists, it should contain at least H - 1 tiles.
        if not, Shik can't increase (his or her) X by H - 1, because enough tiles doesnt exist.
        and at the same time, it should have W - 1 more tiles, for the same reason.
        each # will either change only one parameter(X or Y) by one. so these tiles are not conflicting with each other.
        so we need to have at least H - 1 + W - 1 tiles to perform the moves, dis-including the first tile.(because Shika is in the 1,1 initially).
        so if the matrix a contains H + W - 1 #s, due to these facts, exactly H - 1 tiles are there for Shik to go rigth, and W - 1 to down.

        so if we have H + W - 1 #s, the answer can only be possible.

        phew! I think it took 1.5H to proove this little code :)
    */

    int H, W;
    cin >> H >> W;

    char a[H][W];
    int sharps = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> a[i][j];
            if (a[i][j] == '#')
                sharps++;
        }
    }

    cout << (sharps == H + W - 1 ? "Possible" : "Impossible") << endl;

    return 0;
}
