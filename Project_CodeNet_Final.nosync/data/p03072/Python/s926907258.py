n=int(input())
h=list(map(int,input().split()))
cnt=1
for i in range(1,len(h)):
  hotel=h[i]
  c=True
  for j in range(0,i):
    if h[i]<h[j]:
      c=False
      break
  if c:
    cnt+=1
print(cnt)