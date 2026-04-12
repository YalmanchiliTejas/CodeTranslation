
def solve():
    N = raw_input()
    K = int(raw_input())
    L = len(N)
    # digN = []
    # rem = N
    # while (rem != 0):
    #     digN.append(rem%10)
    #     rem = rem / 10
    digN = [int(d) for d in N]
    dp0 = [[1 for i in range(K+1)] for i in range(L)]
    dp1 = [[1 for i in range(K+1)] for i in range(L)]
    dp0[0][0] = 1
    dp1[0][0] = 1
    dp0[0][1] = digN[L-1]
    dp1[0][1] = 9
    for i in range(2, K+1):
        dp0[0][i] = 0
        dp1[0][i] = 0
    for i in range(1, L):
        for j in range(1, K+1):
            if digN[L - 1 - i] > 0:
                dp0[i][j] = (digN[L - 1 - i] - 1) * dp1[i-1][j-1] + dp0[i-1][j-1] + dp1[i-1][j]
            else:
                dp0[i][j] = dp0[i-1][j]
            dp1[i][j] = 9 * dp1[i-1][j-1] + dp1[i-1][j]
    print dp0[L-1][K]

if __name__ == '__main__':
    solve()
