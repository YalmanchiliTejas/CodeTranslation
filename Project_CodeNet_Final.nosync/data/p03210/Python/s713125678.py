# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

X = ir()
bl = (3 <= X <= 7) and X&1
print('YES' if bl else 'NO')
