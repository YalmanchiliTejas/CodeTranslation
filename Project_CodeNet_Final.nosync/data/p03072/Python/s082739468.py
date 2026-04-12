N = int(input())
H = [int(i) for i in input().split()]

highest = 0
count = 0

for hi in H:
  if hi >= highest:
    count += 1
    highest = hi

print(count)
