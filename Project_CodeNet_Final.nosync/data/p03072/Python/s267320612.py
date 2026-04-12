n = int(input())
h = list(map(int, input().split()))

count = 0
highest = 0

for i in range(n):
  if(h[i] >= highest):
    count += 1
    highest = h[i]

print(count)