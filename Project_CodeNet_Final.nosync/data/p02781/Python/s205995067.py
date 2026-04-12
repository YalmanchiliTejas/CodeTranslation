import itertools

def read():
    N = str(input().strip())
    K = int(input().strip())
    return N, K

def solve(N, K):
    L = len(N)
    D = [int(N[i]) for i in range(L)]
    dp0 = [[0 for k in range(K+1)] for i in range(L+1)]
    dp1 = [[0 for k in range(K+1)] for i in range(L+1)]
    
    dp0[0][0] = 1
    for i in range(L):
        for k in range(K+1):
            if k < K and D[i] > 0:
                dp0[i+1][k+1] += dp0[i][k]
                for d in range(1, D[i]):
                    dp1[i+1][k+1] += dp0[i][k]
            if D[i] == 0:
                dp0[i+1][k] += dp0[i][k]
            else:
                dp1[i+1][k] += dp0[i][k]
            if k < K:
                for d in range(1, 10):
                    dp1[i+1][k+1] += dp1[i][k]
            dp1[i+1][k] += dp1[i][k]
    return dp0[L][K] + dp1[L][K]


if __name__ == '__main__':
    inputs = read()
    print("%d" % solve(*inputs))
