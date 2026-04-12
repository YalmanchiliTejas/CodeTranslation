import sys
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]
coef1, coef2 = [], []

for i in range(N):
    p = 1 if i in [0, N-1] else 2
    coef1.append(p*(1 if i%2==0 else -1))
    coef2.append(p*(-1 if i%2==0 else 1))

A.sort()
coef1.sort()
coef2.sort()
ans = max(sum(Ai*p for Ai, p in zip(A, coef1)), sum(Ai*p for Ai, p in zip(A, coef2)))
print(ans)