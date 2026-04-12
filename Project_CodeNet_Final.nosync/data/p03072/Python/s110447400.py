mt_count=int(input())
heights = list(map(int, input().split()))
count = 0

i=1

for i in range(mt_count):
  check_flag = 1
  for j in range(i):
    if heights[j] > heights[i]:
      check_flag = 0
  if check_flag == 1:
    count += 1

print(count)