# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N, X = lr()
burger = [0] * (N+1)
burger[0] = 1
patty = [0] * (N+1)
patty[0] = 1
for i in range(1, N+1):
    burger[i] = burger[i-1] * 2 + 3
    patty[i] = patty[i-1] * 2 + 1

def solve(N, take):
    """レベルNバーガーのtake層目までのpattyの数を返す"""
    if N == 0:
        return min(1, take)
    mid = burger[N] // 2 + 1
    if take == mid:
        return patty[N-1] + 1
    if take > mid:
        return patty[N-1] + 1 + solve(N-1, take-mid)
    else:
        return solve(N-1, max(0, take-1))

answer = solve(N, X)
print(answer)
# 31