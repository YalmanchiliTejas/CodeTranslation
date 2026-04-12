S = input()
N = len(S)
K = int(input())

def cmb(n, r):
    if r < 0 or r > n:
        return 0
    if r == 1:
        return n
    elif r == 2:
        return n * (n-1) // 2
    else:
        return n * (n-1) * (n-2) // (3 * 2) 

def rec(i, k, isSmaller):
    if k == 0:
        return 1

    if i == N:
        return 0
    
    if isSmaller:
        return cmb(N-i, k) * pow(9, k)
    else:
        if S[i] == '0':
            return rec(i+1, k, False)
        else:
            zero = rec(i+1, k, True)
            between = rec(i+1, k-1, True) * (int(S[i]) - 1)
            same = rec(i+1, k-1, False)
            return zero + between + same

print(rec(0, K, False))
