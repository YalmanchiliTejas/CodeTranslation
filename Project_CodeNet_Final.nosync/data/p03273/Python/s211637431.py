# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

H, W = lr()
A = [sr() for _ in range(H)]
B = []
for a in A:
    if '#' in a:
        B.append(a)

B = zip(*[b for b in zip(*B) if '#' in b])
for b in B:
    print(*b, sep='')
