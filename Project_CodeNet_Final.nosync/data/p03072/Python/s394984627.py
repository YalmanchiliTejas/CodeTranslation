N = int(input())
H = list(map(int,input().split()))
mx = H[0]
ans = 0
for h in H:
  if h >= mx:
    ans += 1
    mx = h
print(ans)
