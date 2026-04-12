def main():
    MOD = 10**9+7
    n = int(input())
    A = list(map(int,input().split()))

    ans = 0
    Asum = sum(A)%MOD
    for a in A:
        Asum-=a
        ans += a*Asum
        ans %=MOD
    print(ans)
main()