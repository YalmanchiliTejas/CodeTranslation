def main():
    mod = 10**9 + 7
    n = int(input())
    a = [int(i) for i in input().split()]
    _s = sum(a)
    s = [_s - ai for ai in a]
    ans = 0
    for i in range(n):
        ans = ((a[i] * s[i]) % mod + ans) % mod
    print(ans * pow(2, mod - 2, mod) % mod)


if __name__ == '__main__':
    main()
