times = int(input())
numbers = list(map(int, input().split()))
result = 0
sum_numbers = sum(numbers)
calc = []

for i in range(times - 1):
  sum_numbers -= numbers[i]
  calc.append(sum_numbers)

for i in range(times - 1):
  calc[i] *= numbers[i]
  
print(sum(calc) % (10 ** 9 + 7))