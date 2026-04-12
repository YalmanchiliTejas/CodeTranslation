n=int(input())
l=list(map(int,input().split()))
cnt=1
max_h=-1
for i in range(n-1):
  max_h=max(l[i],max_h)
  if l[i+1]>=max_h:
    cnt+=1
print(cnt)