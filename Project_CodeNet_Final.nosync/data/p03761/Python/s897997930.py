n = int(input())
S = [input() for i in range(n)]
import sys, copy, math, heapq, bisect
from itertools import accumulate
from collections import deque, defaultdict, Counter
input = sys.stdin.readline # 文字列の入力のとき'/n'まで受け取るので注意!!!
sys.setrecursionlimit(500000)

ans = [5000]*26
for i in range(n):
    a = [0]*26
    for j in range(len(S[i])):
        a[ord(list(S[i])[j])-ord('a')] += 1

    for j in range(26):
        ans[j] = min(ans[j],a[j])

print(''.join(sorted(list(''.join([chr(ord('a')+i)*ans[i] for i in range(26)])))))