#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8 ff=unix


def solv(N, K):
    # print('solv', N, K)
    # K == 0 なら条件を満たしたものが一つある
    if K == 0:
        # print('   ret', 1)
        return 1
    # len(N) < K ならば不可能
    if len(N) < K:
        # print('   ret', 0)
        return 0

    # 場合の数
    count = 0

    #  3abcd のような 場合
    #  29999
    #  19999 のような数を加算する
    if N[0] > 1:
        count += (N[0]-1) * solv([9] * (len(N)-1), K-1)
    #  その数を消費する場合
    if N[0] > 0:
        count += solv(N[1:], K-1)
    # 消費しない場合
    if N[0] == 0:
        count += solv(N[1:], K)
    else:
        count += solv([9] * (len(N)-1), K)

    # print('   ret count=', count)
    return count


if __name__ == "__main__":

    N = list(map(int, input()))
    K = int(input())
    ans = solv(N, K)

    print(ans)
