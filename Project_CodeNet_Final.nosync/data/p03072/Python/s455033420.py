n=int(input())
li=list(map(int,input().split()))
count=0
for i in range(1,n):
  if li[i] >= max(li[0:i]):
    count +=1
print(count+1)