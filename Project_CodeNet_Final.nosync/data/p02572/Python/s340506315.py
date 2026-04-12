N = int(input())
A = list(map(int, input().split()))
MOD = 10**9 + 7
A.sort()
ans = 0
sumA = sum(A)
for i in range(N):
    sumA -= A[i]
    for j in range(i+1,N):
        if A[i] > A[j]:
            continue
        ans += (A[i] * (sumA % MOD)) %MOD
        break

print(ans % MOD)
