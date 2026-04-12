n=int(input())
h=list(map(int,input().split()))
x=0
count=0
for i in range(n):
  if x<=h[i]:
    x=h[i]
    count+=1
print(count)