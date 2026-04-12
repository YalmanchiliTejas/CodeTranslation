# -*- coding: utf-8 -*-
import sys

# 標準入力を取得
A, B, C, X, Y = list(map(int, input().split()))

# 求解処理
ans = sys.maxsize
max_c = 2 * max(X, Y)
for c in range(0, max_c + 1, 2):
    a = max(X - c // 2, 0)
    b = max(Y - c // 2, 0)
    price = a * A + b * B + c * C
    ans = min(ans, price)

# 結果出力
print(ans)
