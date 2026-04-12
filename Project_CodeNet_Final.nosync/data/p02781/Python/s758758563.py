N = list(map(int,input()))
K = int(input())
L = len(N)

def comb(n,k):
    if n < 0 or k < 0 or k > n:
        return 0
    ans = 1
    for i in range(k):
        ans *= n-i
    for i in range(k):
        ans //= i+1
    return ans

i = 0
D = [0] * K
M = K
for k in range(K):
    while i < L and N[i] == 0:
        i += 1
    if i < L:
        D[k] = i
        i += 1
    else:
        M = k
        break

ans = 0
for k in range(M):
    i = D[k]
    ans += comb(L-1-i,K-k)*(9**(K-k))
    ans += (N[i]-1) * comb(L-1-i,K-1-k)*(9**(K-1-k))
if K == M:
    ans += 1

print(ans)
