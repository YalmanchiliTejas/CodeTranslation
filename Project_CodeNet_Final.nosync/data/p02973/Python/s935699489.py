# https://atcoder.jp/contests/abc134/tasks/abc134_e

def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
from collections import deque
from bisect import bisect_left

N = INT()
A = []

for _ in range(N):
    A.append(INT())

t = deque([A[0]])
for a in A[1:]:
    i = bisect_left(t, a) - 1
    if i == -1:
        t.appendleft(a)
    else:
        t[i] = a

print(len(t))
