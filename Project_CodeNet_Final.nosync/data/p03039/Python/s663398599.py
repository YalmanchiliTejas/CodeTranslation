MAX = 10**9 + 7

def mod_inv(i, mod):
    return pow(i, mod-2, mod)

def combination(_N, _K):
    if _K > (_N/2):
        _K = _N - _K
    up = 1
    low = 1
    for i in range (_K):
        up = up * (_N - i) % MAX
        low = low * (i + 1) % MAX
    ret = up * mod_inv(low, MAX) % MAX
    return ret

def cum_sum(N):
    return N * (N+1) // 2

def solve2():
    N, M, K = [int(_) for _ in raw_input().split()]
    sumx = 0
    for xi in range(1, N+1):
        sumx = (sumx + cum_sum(N) - (N + 1 - xi) * xi)
    sumx = (sumx * M * M) // 2 %MAX
    sumy = 0
    for yi in range(1, M+1):
        sumy = (sumy + cum_sum(M) - (M + 1 - yi) * yi)
    sumy = (sumy * N * N) // 2 %MAX
    ret = (sumx + sumy) * combination(M*N-2, K-2) % MAX
    print ret

if __name__ == '__main__':
    solve2()
