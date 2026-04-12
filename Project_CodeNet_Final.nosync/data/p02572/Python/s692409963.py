#!/usr/bin/env python

def main():
    n = int(input())
    a_arr = list(map(int, input().split()))
    mod = 10**9 + 7

    a_sum = sum(a_arr)

    ans = 0
    for i in range(n):
        a = a_arr[i]
        a_sum -= a
        ans += a * a_sum % mod
        ans %= mod

    print(ans)

if __name__ == '__main__':
    main()
