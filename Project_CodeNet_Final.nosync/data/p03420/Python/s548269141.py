def solve():
    N, K = map(int, input().split())

    res = 0
    for b in range(K+1, N+1):
        res += b-K
        res += (N//b - 1) * (b-K)
        res += (N%b)-K+1 if N%b >= K else 0
    if K == 0:
        res -= N
    print(res)

if __name__ == "__main__":
    solve()