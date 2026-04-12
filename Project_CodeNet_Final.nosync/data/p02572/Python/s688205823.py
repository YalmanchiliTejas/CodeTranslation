import sys


inint = lambda: int(sys.stdin.readline())
inintm = lambda: map(int, sys.stdin.readline().split())
inintl = lambda: list(inintm())
instrm = lambda: map(str, sys.stdin.readline().split())
instrl = lambda: list(instrm())

n = inint()
A = inintl()

S = [0]*(n+1)
ans = 0

for i in range(n):
    S[i+1] = S[i] + A[i]

for i in range(1,n):
    ans += A[i-1]*(S[-1] - S[i])
    ans %= (10**9 + 7)

print(ans % (10**9 + 7))