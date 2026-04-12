n = int(input())
x = 0
y = 0
for i in range(1, n+1):
  x += 800
  if i % 15 == 0:
    y += 200
    
print(x - y)