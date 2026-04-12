import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
INF = float('inf')
MOD = 10**9+7
dy = [0,1,0,-1]
dx = [1,0,-1,0]
ddy = [0,1,1,1,0,-1,-1,-1]
ddx = [1,1,0,-1,-1,-1,0,1]

n = int(input())
S = input()
k = int(input())
t = S[k-1]
res = ""
for s in S:
    if s == t:
        res += s
    else:
        res += '*'
print(res[:-1])