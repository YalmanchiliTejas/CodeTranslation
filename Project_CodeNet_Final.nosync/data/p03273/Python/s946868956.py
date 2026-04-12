import sys

input = sys.stdin.readline
h, w = map(int, input().split())


f = lambda s: zip(*[column for column in s if '#' in column])
L = [input() for _ in range(h)]

for row in f(f(L)):
    print(*row, sep='', end='\n')
