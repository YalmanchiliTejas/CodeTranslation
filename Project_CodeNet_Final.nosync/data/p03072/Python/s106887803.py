n=int(input())
h=list(map(int,input().split()))
i=0
cnt=0
for j in h:
  if i<=j:
    cnt+=1
    i=j
print(cnt)
