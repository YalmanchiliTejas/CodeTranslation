# -*- coding: utf-8 -*-
# 標準入力を取得
N, X, M = list(map(int, input().split()))

# 求解処理
s = {X}
l = [X]
i = 0
while True:
    a = l[-1]**2 % M
    if a in s:
        i = l.index(a)
        break
    else:
        s.add(a)
        l.append(a)

loop_length = len(l) - i
loop_cnt = (N - i) // loop_length
loop_res = (N - i) % loop_length
ans = sum(l[:i]) + loop_cnt * sum(l[i:]) + sum(l[i: i + loop_res])

# 結果出力
print(ans)
