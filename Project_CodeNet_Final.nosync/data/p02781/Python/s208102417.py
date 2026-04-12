import sys
readline = sys.stdin.readline

N = readline().strip()
K = int(readline())

MM = [9, 81, 9 ** 3]

def comb(n, k):
    a = 1
    for i in range(k):
        a *= n - i
    
    for i in range(k):
        a = a // (i + 1)
    
    return a

def xxx(N, K):
    L = len(N)
    if L <= K - 1:
        return 0
    
    if K == 0:
        return 1
    
    a = comb(L - 1, K) * MM[K - 1]

    b = int(N[0]) - 1
    a += b * comb(L - 1, K - 1) * MM[K - 2] if K >= 2 else b
    
    _i = L
    for i in range(1, L):
        if N[i] != '0':
            _i = i
            break

    if _i < L:
        a += xxx(N[_i:], K - 1)
    elif K == 1:
        a += 1
    return a

print(xxx(N, K))