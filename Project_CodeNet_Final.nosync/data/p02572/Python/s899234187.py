#!/usr/bin/env python3
def main():
    _ = int(input())
    A = [int(x) for x in input().split()]
    mod = 10 ** 9 + 7

    square_S = sum(A) ** 2 % mod
    diagonal = sum([x ** 2 % mod for x in A]) % mod
    #  By the Fermat's little theorem
    print(((square_S - diagonal) % mod * pow(2, mod - 2, mod)) % mod)


if __name__ == '__main__':
    main()
