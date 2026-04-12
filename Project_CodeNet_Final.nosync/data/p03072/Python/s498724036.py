n = int(input())

highest = 0
ans = 0

x = list(map(int, input().split()))

for h in x:
  if h >= highest:
    ans += 1
    highest = h
    
print(ans)