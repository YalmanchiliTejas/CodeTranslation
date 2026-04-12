N = int(input())
H = list(map(int, input().split()))
 
pre = 0
ans = 0
 
for h in H:
  if h >= pre:
    pre = h
    ans += 1
print(ans)