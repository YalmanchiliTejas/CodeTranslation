n=int(input())
h=list(map(int,input().split()))
high=0
count=0
for i in range(n):
  if high<=h[i]:
    count=count+1
    high=h[i]
print(count)