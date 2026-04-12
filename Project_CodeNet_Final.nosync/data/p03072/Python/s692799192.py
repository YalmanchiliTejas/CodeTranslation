n = int(input())
h = [int(i) for i in input().split()]
maxh,c = 0,0
for i in h:
  maxh = max(maxh,i)
  if i >= maxh:
    c += 1
    
print(c)

