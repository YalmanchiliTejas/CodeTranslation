# -*- coding: utf-8 -*-
# 標準入力を取得
N, X, M = list(map(int, input().split()))

# 求解処理


def f(x: int, m: int) -> int:
    return x**2 % m


A = [X]
s = {X}
i = 0
while True:
    A_next = f(A[-1], M)
    if A_next in s:
        i = A.index(A_next)
        break
    else:
        A.append(A_next)
        s.add(A_next)

loop_length = len(A) - i
loop_cnt = (N - i) // loop_length
loop_res = (N - i) % loop_length
ans = sum(A[:i]) + loop_cnt * sum(A[i:]) + sum(A[i: i + loop_res])

# 結果出力
print(ans)
