def main():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 10**9+7
    ans = 0
    tmp = 0
    for i in range(n-1, -1, -1):
        ans = (ans+a[i]*tmp) % mod
        tmp = (tmp+a[i]) % mod
    print(ans)


main()
