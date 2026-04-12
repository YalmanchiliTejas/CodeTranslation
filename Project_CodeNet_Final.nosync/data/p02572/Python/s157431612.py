N = int(input())
A = list(map(int,input().split()))
ans = 0
L = A.copy()
for i in range(-2,-len(A)-1,-1):
    L[i] += L[i+1]
for i in range(len(A)-1):
    ans += (A[i] * L[i+1]) % (10**9+7)
    if ans >= 10**9+7:
        ans = ans % (10**9+7)
print(ans)
