
MOD = 998244353


def main():
    global MOD
    N,S = map(int, input().split())
    A = list(map(int, input().split()))
    dp0 = [[0 for i in range(S+1)] for j in range(N)]
    dp1 = [[0 for i in range(S+1)] for j in range(N)]
    dp2 = [[0 for i in range(S+1)] for j in range(N)]


    dp0[0][0] = 1
    dp1[0][0] = 1
    dp2[0][0] = 1
    if A[0] <= S:
        dp1[0][A[0]] = 1
        dp2[0][A[0]] = 1
    for i in range(1,N):
        for j in range(S+1):
            if j + A[i] <= S:
                dp1[i][j+A[i]] = (dp1[i][j+A[i]] + dp0[i-1][j] + dp1[i-1][j])%MOD
                dp2[i][j+A[i]] = (dp2[i][j+A[i]] + dp0[i-1][j] + dp1[i-1][j])%MOD
            dp0[i][j] = (dp0[i][j] + dp0[i-1][j])%MOD
            dp1[i][j] = (dp1[i][j] + dp1[i-1][j] + dp0[i-1][j])%MOD
            dp2[i][j] = (dp2[i][j] + dp2[i-1][j] + dp1[i-1][j] + dp0[i-1][j])%MOD

    print(dp2[N-1][S]%MOD)

main()