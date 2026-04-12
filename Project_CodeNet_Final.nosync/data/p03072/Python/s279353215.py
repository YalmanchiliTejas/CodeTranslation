n = int(input())
hi = list(map(int,input().split()))
mae = 0
count = 0
for i in hi:
  if i>=mae:
    count += 1
    mae = i
print(count)
  
    