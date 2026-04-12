n=int(input())
h=list(map(int,input().split()))
cnt=0
H=[0]
for i in range (n):
  H.append(h[i])
  p=max(H)
  if p<=h[i]:
    cnt+=1
print(cnt)
    