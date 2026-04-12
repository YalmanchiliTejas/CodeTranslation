N = int(input())
height = list(map(int,input().split()))
CC = 0
for i in range(1,N+1):
  if height[i-1] == max(height[0:i]):
    CC += 1
print(CC)