N=int(input())
H=map(int,input().split())
hmax=0
ans=0
for h in H:
  if hmax <= h:
    hmax = h
    ans += 1
print(ans)