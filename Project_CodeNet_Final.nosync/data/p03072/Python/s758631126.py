n = int(input())
h = list(map(int,input().split()))
i= int()
m= int()

count = 0
for i in range(n):
  m=0
  while m < i:
    if h[m] <= h[i]:
      m += 1
    else:
      break
  if m == i:
    count += 1
   
      
print(count)