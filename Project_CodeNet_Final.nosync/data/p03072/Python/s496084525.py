n = int(input())
h = list(map(int, input().split()))
maxi = h[0]
count = 1
for i in range(1,n):
  if h[i]>=maxi:
    count+=1
    if h[i]>maxi:
      maxi = h[i]
print(count)