n = int(input())
hhh = [int(x) for x in input().split()]

max_height = 0
counter = 0
for i in range(n):
  if hhh[i] >= max_height:
    max_height = hhh[i]
    counter += 1

print(counter)