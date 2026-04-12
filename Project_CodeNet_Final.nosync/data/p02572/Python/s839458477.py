#!/usr/bin/env python3
def main():
    _ = int(input())
    A = [int(x) for x in input().split()]
    mod = 10 ** 9 + 7

    lst = [sum(A)]
    for j in A:
        lst.append(lst[-1] - j)
    ans = 0
    for index, i in enumerate(A):
        ans += i * lst[index + 1] % mod
    print(ans % mod)


if __name__ == '__main__':
    main()
