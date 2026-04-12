n = int(input())
l = list(map(int, input().split()))

maximum = -1 
count = 0
for i in l:
  if i > maximum:
    maximum = i
  if i == maximum:
    count += 1

print(count)

