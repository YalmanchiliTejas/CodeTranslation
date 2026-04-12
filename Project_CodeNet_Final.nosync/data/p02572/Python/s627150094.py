def main():
    n = int(input())
    a = list(map(int,input().split()))
    mod = 10**9+7
    S = sum(a)
    ans = 0
    for i in range(n):
        ans += (a[i] * (S-a[i]))
    print(ans//2%mod)

if __name__ == "__main__":
    main()
