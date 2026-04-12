n = int(input())
hotels = list(map(int, input().split()))

view = 0
cnt = 0
for i in range(n):
  if hotels[i] >= view:
    cnt += 1
    view = hotels[i]
    
print(cnt)