n=int(input())
h=list(map(int,input().split()))
ans=0
highest=0
for i in range(n):
  if h[i] >= highest:
    ans += 1
    highest=h[i]
print(ans)