n = int(input())
height = list(map(int,input().split()))

no_ocean = 0

for i in range(n):
  for k in range(i+1):
    if height[k] > height[i]:
      	no_ocean += 1
      	break
    else:
        continue
        
print(n - no_ocean)
    