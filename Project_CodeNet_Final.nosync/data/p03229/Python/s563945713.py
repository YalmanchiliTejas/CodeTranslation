#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = [0] * 2 ;count = 0 ;pro = 1

n=int(input())
A=[int(input()) for i in range(n)]
A.sort()
# if n % 2 == 0:
# 1の処理
tmp = 0;k=0
k+=n//2-1; tmp += -2*sum(A[:k])
tmp += -1*A[k]; k += 1
tmp += (-1)**n*A[k]; k += 1
tmp += 2 * sum(A[k:])
ans[0] = tmp

# 2の処理
tmp = 0;k=0
k+=n//2-1+(n%2); tmp += -2*sum(A[:k])
# print(tmp,A[:k])
tmp += (-1)**(n+1)*A[k]; k += 1
tmp += A[k]; k += 1
tmp += 2 * sum(A[k:])
ans[1] = tmp

# print(A);print(ans)
print(max(ans))


