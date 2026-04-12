N = int(input())
h = list(map(int, input().split()))
ans = 0
max_h = h[0]
for hi in h:
  if max_h <= hi:
    max_h = hi
    ans +=1
print(ans)