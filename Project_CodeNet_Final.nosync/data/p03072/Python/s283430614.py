n = int(input())
h = list(map(int,input().split()))
count = 0
z = 0

for i in range(n):
    if z <= h[i]:
      count = count + 1
      z = h[i]
           
print(count)