from itertools import accumulate


def main():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 10 ** 9 + 7
    ac = list(accumulate(a))
    ans = 0
    for i in range(n):
        ans += a[i] * (ac[-1] - ac[i])
        ans %= mod
    print(ans)


if __name__ == '__main__':
    main()
