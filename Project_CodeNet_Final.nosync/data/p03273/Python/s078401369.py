# ABC107b
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

h, w = map(int, input().split())
a = [input()[:-1] for _ in range(h)]

ansX = []
ansY = []

for y in range(h):
    flag = True
    for x in range(w):
        if (a[y][x] == '#'):
            flag = False
    if (flag):
        ansY.append(y)

for x in range(w):
    flag = True
    for y in range(h):
        if (a[y][x] == '#'):
            flag = False
    if (flag):
        ansX.append(x)
#print(ansX, ansY)
for y in range(h):
    if (y in ansY):
        continue
    for x in range(w):
        if (x in ansX):
            continue
        print(a[y][x], end='')
    print('')