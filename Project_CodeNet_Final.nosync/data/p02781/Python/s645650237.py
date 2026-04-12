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
        for less in range(2):
            for k in range(size):
                for x in range(10 if less else N[i] + 1):
                    #print((i, less, k), x, (i+1, int(less or x < N[i]), k + (1 if x else 0)))
                    dp[i+1][less or x < N[i]][k + (1 if x else 0)] += dp[i][less][k]
        #print(dp[i+1])

    print(dp[-1][0][K] + dp[-1][1][K])

if __name__ == "__main__":
    resolve()
