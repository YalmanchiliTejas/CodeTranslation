n = int(input())
h = list(map(int, input().split()))

height = h[0]
ans = 0

for i in h:
  if height <= i:
    ans += 1
    height = i
  
print(ans)