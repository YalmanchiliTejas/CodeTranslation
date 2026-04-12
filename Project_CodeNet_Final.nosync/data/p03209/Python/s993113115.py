import sys
sys.setrecursionlimit(10000)

N,X = map(int, input().split())

ans = 0
for n in range(N,-1,-1):
  if X > (2**(n+2) - 3) / 2 :
    ans += 2**n #- 1 + 1
    X = X - (2**(n+1) - 3) - 2
  else:
    X -= 1
print(ans)