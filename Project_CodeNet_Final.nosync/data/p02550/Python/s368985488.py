#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n, x, m = map(int, input().split())
seen = [-1] * m
is_done = True
ans = 0
for i in range(n):
    if i == 0:
        val = x
    else:
        val = val * val % m
    if seen[val] != -1:
        loop_len = i - seen[val]
        loop_val = val
        is_done = False
        cnt = i
        break
    else:
        seen[val] = i
        ans += val
if is_done:
    print(ans)
    exit()
n -= (cnt + 1)

val = loop_val
loop_sum = 0
for i in range(loop_len):
    val = val * val % m
    loop_sum += val
ans += (n // loop_len) * loop_sum

val = loop_val
for i in range(n % loop_len):
    val = val * val % m
    ans += val

print(ans + loop_val)