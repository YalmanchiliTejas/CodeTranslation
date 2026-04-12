import numpy as np
i8 = np.int64


def solve(N, X, M):
    memo_val = np.zeros(M, i8)
    memo_i = np.zeros(M, i8)
    ret = 0
    a = X
    for i in range(1, N):
        ret += a
        if memo_i[a] > 0:
            u = (N - memo_i[a]) // (i - memo_i[a])
            v = (N - memo_i[a]) % (i - memo_i[a])
            ret = u * (ret - memo_val[a])
            nokori = v + memo_i[a]
            for j in range(M):
                if memo_i[j] == nokori:
                    ret += memo_val[j]
            return ret
        memo_i[a] = i
        memo_val[a] = ret
        a = a ** 2 % M
    ret += a
    return ret

def main():
    f = open(0)
    N, X, M = [int(x) for x in f.readline().split()]
    ans = solve(N, X, M)
    print(ans)

main()