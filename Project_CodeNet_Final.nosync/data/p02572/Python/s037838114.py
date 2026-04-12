def main():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 10 ** 9 + 7
    s = sum(a)
    ans = 0
    
    for i in range(n):
        s -= a[i]
        ans = (ans + a[i] * s) % mod
    print(ans)

main()