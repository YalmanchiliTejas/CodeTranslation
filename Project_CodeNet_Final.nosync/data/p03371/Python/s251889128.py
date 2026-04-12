# -*- coding: utf-8 -*-

# 入力
A, B, C, X, Y = map(int, input().split())

# 処理
ans = [i * 2*C + max(0, X-i)*A + max(0, Y-i)*B for i in range(0, 100001)]

# 出力
print(min(ans))