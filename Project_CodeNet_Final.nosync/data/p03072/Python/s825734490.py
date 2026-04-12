N = int(input())
numbers = list(map(int, input().split(' ')))

count = 0
counter = 0
for num in range(N):
    for num1 in range(num):
      if numbers[num] >= numbers[num1]:
        counter += 1
      else:
        continue
    if counter == num:
      count += 1
    counter = 0

print(count)