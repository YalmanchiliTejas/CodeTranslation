n = int(input())
h = list(map(int,input().split()))
maxh = 0
c = 0
for i in range(n):
  if h[i] >= maxh:
    c += 1
    maxh = h[i]
print(c)
    
    