import sys
stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)
import itertools

i_i = lambda: int(i_s())
i_l = lambda: list(map(int, stdin.readline().split()))
i_s = lambda: stdin.readline().rstrip()

N, M = i_l()
matrix = [[0] * N for _ in range(N)]

for i in range(M):
    a, b = i_l()
    matrix[a-1][b-1] = 1
    matrix[b-1][a-1] = 1

cnt = 0
for x in itertools.permutations(range(N)):
    if x[0] != 0:
        break
    factor = 1
    for i in range(N-1):
        factor *= matrix[x[i]][x[i+1]]
    cnt += factor

print(cnt)