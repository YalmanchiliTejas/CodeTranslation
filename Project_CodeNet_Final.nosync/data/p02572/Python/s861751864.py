# -*- coding: utf-8 -*-
# 標準入力を取得
N = int(input())
A = list(map(int, input().split()))

# 求解処理
ans = 0
sum_A_j = sum(A)
for A_i in A:
    sum_A_j -= A_i
    ans += A_i * sum_A_j
    ans %= 10**9 + 7

# 結果出力
print(ans)
