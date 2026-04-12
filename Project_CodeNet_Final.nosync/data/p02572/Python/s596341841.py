N = int(input())
A = list(map(int, input().split()))
s = 0
S = 0
for i in range(N):
    s += A[i]
    S += (A[i])**2
ans = (s**2 - S)//2
print(ans % (10**9+7))