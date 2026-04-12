import sys
import numpy as np

stdin = sys.stdin

ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))  # applies to only numbers
rs = lambda: stdin.readline().rstrip()  # ignores trailing space

N = ri()
A = np.array(rl())
answer = 0
while A.max() >= N:
    B = A // N
    count = B.sum()
    answer += count
    A = A - B * N + (count - B)

print(answer)
