#!/usr/bin/env python3

import functools


M = 10 ** 9 + 7


def sum_mod(xs):
    return functools.reduce(lambda x, y: (x + y) % M, xs) % M


def compute(bs):
    term1 = sum_mod(bs) * sum_mod(bs) % M
    term2 = sum_mod(b * b for b in bs)
    double_res = (term1 - term2) % M
    inv2 = pow(2, M - 2, M)
    res = double_res * inv2 % M
    return res


def main():
    n = int(input())
    bs = [int(b) for b in input().split()]
    res = compute(bs)
    print(res)


if __name__ == '__main__':
    main()