n= int(input())
h = list(map(int, input().split()))
mymax=h[0]
count=1
for i in range(1,n):
  if h[i]>=mymax:
    count +=1
    mymax=h[i]
    
print(count)