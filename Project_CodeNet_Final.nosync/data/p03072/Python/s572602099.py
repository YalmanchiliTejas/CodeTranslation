n = int(input())
h = list(map(int, input().split()))
cnt=1
maxi=h[0]
for i in range(1,len(h)):
  if h[i]>=maxi:
    cnt+=1
    maxi = h[i]
print(cnt)