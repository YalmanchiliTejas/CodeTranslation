n=int(input())
h=list(map(int,input().split()))
max=h[0]
count=0
for i in range(1,n):
  if h[i]>=max:
    max=h[i]
    count+=1
print(count+1)
