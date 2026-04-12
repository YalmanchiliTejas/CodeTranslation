#i!/usr/bin/env python
# coding: utf-8

import sys
input = sys.stdin.readline

N, X = list(map(int, input().split()))
layers = [1]
patties = [1]
l = 1
p = 1
for _ in range(N):
    l = 2 * l + 3
    layers.append(l)
    p = 2 * p + 1
    patties.append(p)


def dfs(n, x):
    if n == 0:
        return patties[0]
    p = layers[n-1]
    if x == 1:
        return 0
    if x <= 1 + p:
        return dfs(n-1, x-1)
    if x == 1 + p + 1:
        return patties[n-1] + 1
    if x <= 1 + p + 1 + p:
        return patties[n-1] + 1 + dfs(n-1, x-(1+p+1))
    return patties[n]


def main():
    print(dfs(N, X))


if __name__ == '__main__':
    main()
