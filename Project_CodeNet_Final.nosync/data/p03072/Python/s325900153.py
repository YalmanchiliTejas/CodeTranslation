num = int(input())
height = list(map(int,input().split()))
SUM = 1
comp = height[0]

for i in range(1,num):
  if comp <= height[i]:
    comp = height[i]
    SUM += 1

print(SUM)