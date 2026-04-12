N = int(input())
A = list(map(int, input().split()))
 
A_j = sum(A)
mod = (10**9)+7
res = 0
for i in range(N-1):
    A_j -= A[i]
    res += (A[i] * (A_j % mod)) % mod

print(res % mod)