#!/usr/bin/env python3
# https://atcoder.jp/contests/abc124/tasks/abc124_b

n = int(input())
h = [0] + [int(x) for x in input().split()]
cnt = 0
for i in range(1, len(h)):
    if len([j - h[i] for j in h[:i + 1] if j - h[i] > 0]) == 0:
        cnt += 1
print(cnt)
