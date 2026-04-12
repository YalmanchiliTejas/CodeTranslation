#!/usr/bin/env python3
def main():
    _ = int(input())
    A = [int(x) for x in input().split()]
    mod = 10 ** 9 + 7

    sum_A = sum(A) % mod
    ans = 0
    for a in A:
        sum_A += mod - a if sum_A < a else -a
        ans += a * sum_A
        ans %= mod
    print(ans % mod)


if __name__ == '__main__':
    main()
