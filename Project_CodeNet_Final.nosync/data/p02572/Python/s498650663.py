def main():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 10**9+7
    sums = [None]*(n-1)
    s = 0
    ans = 0
    for i in range(n-1):
        s += a[i]
        s %= mod
        sums[i] = s
    for i in range(n-1):
        ans += a[n-1-i]*sums[n-2-i]
        ans %= mod
    
    print(ans)

if __name__ == "__main__":
    main()