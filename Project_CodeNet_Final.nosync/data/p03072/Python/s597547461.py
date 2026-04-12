num = int(input())

height = input().split()
height = [int(i) for i in height]

base = height[0]
heighest = height[0]
ans = 0
for i in height:
  if i>=heighest:
    ans += 1
    heighest = i
    
print(ans)