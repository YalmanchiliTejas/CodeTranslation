def solve(N, K):
    if K==0:
        return N*N
    ans = 0
    for b in range(K+1, N+1):
        ans += (N//b) * (b-K) + max(0, (N%b) - (K-1))
    return ans

N, K = map(int, input().split())
print(solve(N, K))