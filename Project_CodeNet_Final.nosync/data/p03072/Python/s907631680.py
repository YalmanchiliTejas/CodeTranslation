n = int(input())
h = list(map(int, input().split()))

visible_hotels = 1
for i in range(1, n):
  l = h[:i+1]
  if max(l) == h[i]:
    visible_hotels = visible_hotels + 1

print(visible_hotels)
  

