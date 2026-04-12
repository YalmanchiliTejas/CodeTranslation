N = int(input())
h = list(map(int, input().split()))
count = 0
for i, x in enumerate(h):
  if i == 0:
    count += 1
  else:
    if max(h[:(i)]) <= x: 
      count += 1
print(count)