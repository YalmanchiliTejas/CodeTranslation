import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

S = sr()
bl = False
for x, y in zip(S, S[1:]):
    if x+y == 'AC':
        bl = True

print('Yes' if bl else 'No')
# 45