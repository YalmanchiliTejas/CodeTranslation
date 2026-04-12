def main():
    n = int(input())
    a = [int(v) for v in input().split()]
    m = 1000000007
    ans = 0
    ss = sum(a[1:])
    for i in range(n-1):
        ans += a[i]*ss
        ss -= a[i+1]
        ans %= m
    print(ans)

main()