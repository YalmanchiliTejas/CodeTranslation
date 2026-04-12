import sys
input = sys.stdin.readline
M = 1000000007
n = int(input())
A = list(map(int, input().split()))
ans = 0
s = 0
for i in range(n):
    s += A[i]
    s %= M

for i in range(n):
    s = s - A[i]
    if s < 0:
        s += M
    ans += A[i] * s
    ans %= M
print(ans)