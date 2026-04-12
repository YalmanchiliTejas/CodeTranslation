from sys import stdin, stdout


def solve():
    n = int(input())
    A = [int(i) for i in stdin.readline().split()]
    dp = [[i,0] for i in A]
    t = [[0,0] for _ in range(len(A))]
    for i in range(1, len(A)):
        for j in range(i, len(A)):
            l = A[j-i] + dp[j][1]
            r = A[j] + dp[j-1][1]
            if l > r:
                t[j][0] = l
                t[j][1] = dp[j][0]
            else:
                t[j][0] = r
                t[j][1] = dp[j-1][0]
        dp = t
        t = [[0,0] for _ in range(len(A))]
    return dp[-1][0] - dp[-1][1]


print(solve())