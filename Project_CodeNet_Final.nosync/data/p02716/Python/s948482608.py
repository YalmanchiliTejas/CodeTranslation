from sys import setrecursionlimit, exit
setrecursionlimit(1000000000)

def main():
    n = int(input())
    a = tuple(map(int, input().split()))
    odds = [0] * ((n + 1) // 2 + 1)
    for i, v in enumerate(a[::2]):
        odds[i+1] = odds[i] + v
    if n % 2 == 0:
        evens = [0] * (n // 2 + 1)
        for i, v in enumerate(a[1::2]):
            evens[i+1] = evens[i] + v
        ans = -float('inf')
        for i in range(n // 2 + 1):
            ans = max(ans, odds[i] + evens[-1] - evens[i])
        print(ans)
        return
    ans = odds[-1] - odds[1]
    dp = [float('inf')] * n
    dp[0] = a[0]
    dp[1] = a[1]
    ans = max(ans, max(a[:2]) + odds[-1] - odds[2])
    for i in range(2, n):
        if i % 2 == 0:
            dp[i] = dp[i-2] + a[i]
        else:
            dp[i] = max(dp[i-2], dp[i-3]) + a[i]
            ans = max(ans, max(dp[i-1], dp[i]) + odds[-1] - odds[i//2+2])
    print(ans)

main()