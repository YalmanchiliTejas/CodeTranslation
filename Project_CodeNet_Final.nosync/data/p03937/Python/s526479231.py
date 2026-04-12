import sys
from sys import stdin

h, w = map(int, stdin.readline().rstrip().split())
a = [stdin.readline().rstrip() for i in range(h)]
count = 0
for i in a:
    for j in i:
        if j == '#':
            count += 1
if h + w - 1 == count:
    print('Possible')
else:
    print('Impossible')