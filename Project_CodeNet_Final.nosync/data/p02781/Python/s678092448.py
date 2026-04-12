def main():
    import sys
    input = sys.stdin.readline

    N = input().rstrip('\n')
    L = len(N)
    K = int(input())

    dp0 = [[0] * (K+1) for _ in range(L+1)]
    dp1 = [[0] * (K+1) for _ in range(L+1)]
    dp0[0][0] = 1
    for i in range(L):
        for k in range(K+1):
            m = int(N[i])
            if m == 0:
                dp0[i+1][k] += dp0[i][k]
                dp1[i+1][k] += dp1[i][k]
            else:
                dp1[i+1][k] += dp0[i][k] + dp1[i][k]
            if k+1 <= K:
                if m != 0:
                    dp0[i+1][k+1] += dp0[i][k]
                    dp1[i+1][k+1] += dp0[i][k] * (m-1) + dp1[i][k] * 9
                else:
                    dp1[i + 1][k + 1] += dp1[i][k] * 9
    print(dp0[-1][-1] + dp1[-1][-1])


if __name__ == '__main__':
    main()
