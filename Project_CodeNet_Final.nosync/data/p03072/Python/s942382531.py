n=int(input())
h=list(map(int,input().split()))
count=0
taka=0
for i in range(n):
  if h[i]>=taka:
    taka=h[i]
    count+=1
    
print(count)