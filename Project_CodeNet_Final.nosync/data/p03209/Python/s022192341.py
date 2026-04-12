#!/usr/bin/env python
# -*- coding: utf-8 -*-

# AtCoder Beginner Contest 115：D - Christmas


# 各レベルの長さ
L = [1]+[0]*50
for i in range(50):
    L[i+1] = 3+L[i]*2
# print L

# 各レベルに含まれるパティの数
P = [1]+[0]*50
for i in range(50):
    P[i+1] = 1+P[i]*2
# print P


# 'B' + L[l-1] + 'P' + L[l-1] + 'B'
def lp(l, n):
    if l == 0:
        return 1
    elif n == 1:
        # 'B'
        return 0
    elif 1 < n <= 1+L[l-1]-1:
        # 'B' + L[l-1]の一つ手前まで
        return lp(l-1, n-1)
    elif n == 1+L[l-1]:
        # 'B' + L[l-1]
        return P[l-1]
    elif n == 1+L[l-1]+1:
        # 'B' + L[l-1] + 'P'
        return P[l-1]+1
    elif 1+L[l-1]+1 < n <= 1+L[l-1]+1+L[l-1]-1:
        # 'B' + L[l-1] + 'P' + L[l-1]の一つ手前まで
        return P[l-1] + 1 + lp(l-1, n-(1+L[l-1]+1))
    elif n == 1+L[l-1]+1+L[l-1]:
        # 'B' + L[l-1] + 'P' + L[l-1]
        return P[l-1] + 1 + P[l-1]
    elif n == 1+L[l-1]+1+L[l-1]+1:
        # 'B' + L[l-1] + 'P' + L[l-1] + 'B'
        return P[l-1] + 1 + P[l-1]
    else:
        print 'NG!'
        exit()


def main():
    N, X = [int(i) for i in raw_input().strip().split(' ')]

    print lp(N, X)


if __name__ == '__main__':
    main()
