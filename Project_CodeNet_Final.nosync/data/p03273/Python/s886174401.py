from sys import stderr
from functools import reduce
from operator import add
def f(): return [int(i) for i in input().split()]
def yes(n): print("Yes" if n else "No")
def debug(*x, sep=" ", end="\n"):
    for item in x:
        stderr.write(repr(item))
        stderr.write(sep)
    stderr.write(end)


h, w = f()
grid = []
row = [False for _ in range(h)]
column = [False for _ in range(w)]

for i in range(h):
    ro = input()
    row[i] = (ro == '.' * w)
    grid.append(list(ro))

for j in range(w):
    column[j] = all([(grid[k][j] == '.') for k in range(h)])

for i in range(h):
    if row[i]:
        continue
    for j in range(w):
        if not column[j]:
            print(grid[i][j], end='')
    print()
