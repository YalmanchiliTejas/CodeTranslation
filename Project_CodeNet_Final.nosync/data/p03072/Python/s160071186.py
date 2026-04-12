argN = int(input())
argH = list(map(int,input().split()))
ans = 0
for i in range(argN):
  if argH[i] >= max(argH[:i+1]):
    ans += 1
print(ans)