from itertools import permutations
import sys
#input = sys.stdin.readline
sys.setrecursionlimit(10**7)
N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(M)]

adjm = [[0]*N for _ in range(N)]
for abi in ab:
    adjm[abi[0]-1][abi[1]-1] = 1
    adjm[abi[1]-1][abi[0]-1] = 1

cnt = 0
order = list(range(1, N))
for v in permutations(order):
    last = 0
    for i in v:
        if adjm[last][i] == 1:
            last = i
        else:
            break
    else:
        cnt += 1
print(cnt)