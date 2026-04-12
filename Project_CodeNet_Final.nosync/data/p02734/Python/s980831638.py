import sys
input = sys.stdin.readline

def main():
    n,s = map(int,input().split())
    a = tuple(map(int,input().split()))

    mod = 998244353

    res = 0

    #dp[i][j]:a[i]まででf(L,?) = jとなるLの合計数
    dp = [[0]*3003 for i in range(n)]

    for i in range(n):
        if a[i] < s:
            res = (res+dp[i-1][s-a[i]]*(n-i))%mod
        elif a[i] == s:
            res = (res+(i+1)*(n-i))%mod
        for j in range(3003):
            if j < a[i]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i]])%mod
        dp[i][a[i]] += i+1
    print(res)

if __name__ == "__main__":
    main()