n = int(input())
h = list(map(int,input().split()))

maxh = h[0]
count = 1
for i in range(1,n):
  if h[i]>=maxh: 
    count += 1
    maxh = max(maxh,h[i])
print(count)
