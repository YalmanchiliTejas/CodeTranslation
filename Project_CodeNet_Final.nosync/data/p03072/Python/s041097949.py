n = int(input())
hlist = list(map(int,input().split()))
kijun = hlist[0]
ans = 0
max = hlist[0]

for x in range(0,n):
  if hlist[x] >= max:
    max = hlist[x]
    ans+=1
  #print(hlist[x])
    
print(ans)