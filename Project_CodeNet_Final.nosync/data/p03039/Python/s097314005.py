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

def solve():
    N, M, K = [int(_) for _ in raw_input().split()]
    disSum = (M*N* ((M*(N+1)*(N-1))%MAX + (N*(M+1)*(M-1)) % MAX)) % MAX
    disSum *= mod_inv(6, MAX) % MAX
    ret = disSum * combination(M*N-2, K-2) % MAX
    print ret

if __name__ == '__main__':
    solve()
