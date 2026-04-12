# import itertools
# import math


def solve(N, M):
    return 'Yes' if N == M else 'No'


# N = int(input())
# S = input()
N, M = map(int, input().split())
# A = list(map(int, input().split()))

# P = []
# S = []
# for i in range(N):
#     pp, ss  = map(int, input().split())
#     P.append(pp)
#     S.append(ss)

print(solve(N, M))
