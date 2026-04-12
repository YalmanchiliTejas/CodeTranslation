import sys,math
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
INF = float('inf')
MOD = 10**9+7
dy = [0,1,0,-1]
dx = [1,0,-1,0]
ddy = [0,1,1,1,0,-1,-1,-1]
ddx = [1,1,0,-1,-1,-1,0,1]

n = int(input())
H = list(map(int,input().split()))
cnt = 0
for i in range(n):
    if H[i] == max(H[:i+1]):
        cnt += 1
print(cnt)