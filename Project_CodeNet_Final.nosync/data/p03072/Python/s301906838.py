n = int(input())
h = list(map(int, input().split()))

count = 0
highest = h[0]

for i in h:
  if highest <= i:
    highest = i
    count += 1

print(count)