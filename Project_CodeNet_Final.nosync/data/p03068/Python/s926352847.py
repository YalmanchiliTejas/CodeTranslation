from functools import reduce

N = int(input())
S = input()
K = int(input()) - 1

print(reduce(lambda x, y: x + (y if y == S[K] else '*'), S, ''))
