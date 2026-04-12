n = int(input())
h = list(map(int, input().split()))

ans=0
mh=h[0]
for i in h:
  if i >= mh:
    mh = i
    ans+=1

print(ans)