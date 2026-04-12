#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8 ff=unix


def solv(S):
    if S == 'AAA' or S == 'BBB':
        return 'No'
    return 'Yes'


if __name__ == "__main__":

    S = input()
    ans = solv(S)

    print(ans)
