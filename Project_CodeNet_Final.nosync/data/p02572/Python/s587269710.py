def main():
    from itertools import accumulate
    n, *a = map(int, open(0).read().split())
    m = 10 ** 9 + 7
    *acm, = accumulate(a)
    ans = 0
    for i in range(n):
        rem = acm[-1] - acm[i]
        ans += rem * a[i]
        ans %= m

    print(ans)


if __name__ == '__main__':
    main()
