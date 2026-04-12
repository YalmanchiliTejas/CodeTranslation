#!python3


iim = lambda: map(int, input().rstrip().split())

def resolve():
    N = list(map(int, input()))
    K = int(input())
    size = len(N)

    if size < K:
        print(0)
        return

    dp = [[[0]*(size+1) for j in range(2)] for i in range(size+1)]

    dp[0][0][0] = 1
    for i in range(size):
        for k in range(min(i+1, K+1)):
            dp0, dp1 = dp[i], dp[i+1]

            dp1[1][k+1] += 9 * dp0[1][k]
            dp1[1][k]   +=     dp0[1][k]

            x, y = N[i], dp0[0][k]
            if x == 0:
                dp1[0][k] += y
            else:
                dp1[1][k] += y
                dp1[0][k+1] += y
                dp1[1][k+1] += (x-1) * y
        #print(dp1)

    print(dp[-1][0][K] + dp[-1][1][K])

if __name__ == "__main__":
    resolve()
