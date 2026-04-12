# 02
import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


INF = float('inf')


h, w = LI()
a = []
for _ in range(h):
    a.append(list(S()))

cnt = 0
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            cnt += 1

if cnt == h+w-1:
    print('Possible')
else:
    print('Impossible')
