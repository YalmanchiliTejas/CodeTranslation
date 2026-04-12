n=int(input())
l=list(map(int,input().split()))
max_value=-999
cnt=0
for i in range(n):
  if max_value<=l[i]:
    max_value=max(max_value,l[i])
    cnt+=1
print(cnt)