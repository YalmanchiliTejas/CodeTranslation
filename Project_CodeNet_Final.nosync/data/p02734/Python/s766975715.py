import sys

def main():
    MOD = 998244353
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]

    N,S = LI()
    A = LI()
    dp = [0] * (S+1)
    ans = 0
    for i in range(N):
        dp[0] = i+1
        for j in range(S,0,-1):
            if A[i] > j: break
            dp[j] = (dp[j] + dp[j-A[i]]) % MOD
        ans = (ans + dp[-1] * (N-i)) % MOD
        dp[-1] = 0
    print(ans)

if __name__ == '__main__':
    main()