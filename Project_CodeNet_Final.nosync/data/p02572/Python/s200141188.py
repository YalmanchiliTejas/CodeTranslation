n = int( input().rstrip())
numbers = list( map(int, input().rstrip().split(" ")) )

total = sum(numbers)

m = 10 ** 9 + 7
result = 0
for number in numbers[:-1]:
  total -= number
  result += (total * number)
  result %= m
 
print(result)