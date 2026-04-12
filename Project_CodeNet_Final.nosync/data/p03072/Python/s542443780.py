n = int(input())
h = list(map(int, input().split()))
x = 0
 
h_max=h[0]

for i in range(n):
  if h[i] >= h_max:
      x += 1
      h_max = h[i]
  
print(x)