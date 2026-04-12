n = int(input())
h = list(map(int, input().split()))

count = 1

for i in range(n-1):
  if max(h[:i+1]) <= h[i+1]:
    count += 1
  else:
    pass

print(count)