import sys
input = sys.stdin.readline

N,M = map(int,input().split())
ans = 'No'
if(N==M):ans='Yes'
print(ans)