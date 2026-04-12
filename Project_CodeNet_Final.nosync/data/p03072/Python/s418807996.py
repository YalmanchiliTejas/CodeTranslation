n=int(input())
h=list(map(int,input().split()))
count=0
max=h[0]
for i in range(0,n):
  if h[i]>=max:
    max=h[i]
    count+=1
print(count)