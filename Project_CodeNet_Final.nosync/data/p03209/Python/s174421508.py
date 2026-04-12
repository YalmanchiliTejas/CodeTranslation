# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N, X = lr()
burger = [0] * 51 # 1-indexed
burger[0] = 1
patty = [0] * 51
patty[0] = 1
for i in range(1, N+1):
    burger[i] = 2 * burger[i-1] + 3
    patty[i] = 2 * patty[i-1] + 1

#print(burger)
answer = 0
while X:
    if N == 0:
        answer += 1
        break
    if X <= 1:
        break
    elif X == burger[N]:
        answer += patty[N]
        break
    if X > burger[N] // 2:
        answer += patty[N-1] + 1  # +1は中央部
        X -= burger[N-1] + 2
        N -= 1
        continue
    else:
        X -= 1
        N -= 1

print(answer)
