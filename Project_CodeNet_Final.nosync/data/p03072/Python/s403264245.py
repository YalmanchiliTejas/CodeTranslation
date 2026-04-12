n = int(input())
mountain = [int(x) for x in input().split()]

count = 1

for i in range(n):
  if i == 0:
    h = mountain[0]
    continue
  if mountain[i] < h:
    continue
  else:
    h = mountain[i]
    count += 1

print(count)