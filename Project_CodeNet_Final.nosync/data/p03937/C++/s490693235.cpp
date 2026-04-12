        #include <iostream>
        #include <vector>
        #include <set>
        #include <queue>
        #include <algorithm>
        #include <string>
        #include <cmath>
        using namespace std;
        #define MAX 100
        int is[MAX];
        int h, w;
        string s[8];
        
        // ある1行の終了位置を探すメソッド
        int searchRowEnd(int start, int row) {
            int endCol = -1;     // 終了位置。初期は未設定状態として-1を使用。
            bool onLoad = false; // 現在開始位置～終了位置の間の列かどうか（路上判定と呼んでおく）
            for (int col = 0; col < w; col++) {
                // 終了位置が未設定の時のみ路上判定をする。
                // なぜなら終了位置確定後もtrueになったら困るから
                if (endCol == -1) { 
                    onLoad = col >= start;
                }
                // 路上以外で#がある時　||　開始位置でいきなり#が無い時　例外を返す。
                if (!onLoad && s[row][col] == '#' || col == start && s[row][col] != '#') {
                    return -1;
                }
                // 路上で#がついていれば、道が続いてるということでとりあえず終了位置更新
                if (onLoad && s[row][col] == '#') {
                    endCol = col;
                } else {
                    // 道が続いてなかったら路上ではなくなったとする。
                    // これ以降は終了位置は更新されないため終了位置確定とも言える。
                    onLoad = false;
                }
            }
            // 終了位置確定したものを返す。
            return endCol;
        }
        
        bool judge() {
            // 最初は左上
            int start = 0;
        	for (int row = 0; row < h; ++row) {
        	    // ある行の#の連続の終了位置が次の行の開始位置になるはずだよね　のロジックなので
        	    // 今の行の終了位置を探して、次の行の開始位置にセットしてループ。
        	    // -1が帰って来たときは何かしら条件を満たしてないとする。
        	    start = searchRowEnd(start, row);
        	    if (start == -1) {
        	        return false;
        	    }
        	}
        	// 一番最後は右下の位置じゃないとだめよね
        	return start == w - 1;
        }
        
        int main(void) {
        	cin >> h >> w;
        	for (int i = 0; i < h; ++i) {
        		cin >> s[i];
        	}
        	bool f = judge();
        	cout << (f ? "Possible" : "Impossible") << endl;
        	return 0;
        }