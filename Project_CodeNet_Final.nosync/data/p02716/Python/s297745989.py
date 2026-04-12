# -*- coding: utf-8 -*-
import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
A = list(map(int,readline().split()))
INF = 10 ** 18
# -2 -1 0 1
#dp_use 見ている文字を使った dp_not_use 見ている文字を使わない
dp_use = [-INF] * 4
dp_not_use = [-INF] * 4
dp_not_use[0] = 0

for a in A:
    tmp_use = [-INF] * 4
    tmp_not_use = [-INF] * 4
    for current_diff in range(-2,2):
        if current_diff - 1 >= -2:
            tmp_use[current_diff] = dp_not_use[current_diff-1] + a
        if current_diff + 1 < 2:
            tmp_not_use[current_diff] = max(dp_use[current_diff+1],dp_not_use[current_diff+1]) 
    dp_use = tmp_use
    dp_not_use = tmp_not_use

diff = -1 + (N+1) % 2 
print(max(dp_use[diff],dp_not_use[diff]))