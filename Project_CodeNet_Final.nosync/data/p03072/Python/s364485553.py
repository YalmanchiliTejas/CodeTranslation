import sys
sys.setrecursionlimit(10**6)

n = int(input())
h = list(map(int, input().split()))
#n, m = map(int, input().split())
#s = input()
#s,t = input().split()
#a = [int(input()) for _ in range(n)]
#
#readline = sys.stdin.readline
#n,m = [int(i) for i in readline().split()]
#ab = [[int(i) for i in readline().split()] for _ in range(n)]

ma = 0
ans = 0

for i in range(n):
    if h[i] >= ma:
        ans += 1
    ma = max(ma, h[i])
    
print(ans)