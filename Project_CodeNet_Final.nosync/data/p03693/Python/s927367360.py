import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

r, g, b = input().split()

if int(r+g+b)%4==0:
    print('YES')
else:
    print('NO')
