n=int(input())
h=list(map(int,input().split()))
temp=0
count=0
for i in range(n):
  if h[i]>=temp:
    count=count+1
  temp=max(temp,h[i])
print(count)