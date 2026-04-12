n = int(input())
h = list(map(int, input().split()))

count = 0
high = h[0]

for i in range(n):
  if h[i] >= high :
    count += 1
    high = h[i]

print(count)