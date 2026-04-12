import sys

sys.setrecursionlimit(10 ** 6)


def input(): return sys.stdin.readline().rstrip()

H, W = map(int, input().split())
a = [input() for _ in range(H)]

rows =[r for r in range(H) if '#' in a[r]]
columns = [c for c in range (W) if '#' in [a[r][c] for r in range(H)]]

for r in rows:
    for c in columns:
        print(a[r][c], end="")
    print()