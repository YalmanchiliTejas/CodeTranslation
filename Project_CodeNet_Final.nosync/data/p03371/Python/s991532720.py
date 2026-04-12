# -*- coding: utf-8 -*-
# モジュールのインポート
import sys

# 標準入力を取得
A, B, C, X, Y = list(map(int, input().split()))

# 求解処理
ans = sys.maxsize
for c in range(0, 2 * max(X, Y) + 1, 2):
    a = max(0, X - c // 2)
    b = max(0, Y - c // 2)
    ans = min(ans, A * a + B * b + C * c)

# 結果出力
print(ans)