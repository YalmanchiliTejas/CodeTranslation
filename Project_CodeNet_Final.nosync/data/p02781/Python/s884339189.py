# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = list(map(int, sr()))
K = ir()
dp_dec = [0] * (K+1)
dp_reserved = [0] * (K+1)
dp_reserved[0] = 1
for x in N:
    prev = dp_dec[:]
    # 0の場合はそのままの値
    for k in range(K):
        dp_dec[k+1] += prev[k] * 9  # 1-9の場合
    if x > 0:
        for k in range(K+1):
            dp_dec[k] += dp_reserved[k]  # 0の場合
            if k < K:
                dp_dec[k+1] += dp_reserved[k] * (x - 1)  # 1-9の場合
        dp_reserved[1:] = dp_reserved[:-1]
        dp_reserved[0] = 0

answer = dp_dec[K] + dp_reserved[K]
print(answer)
# 07