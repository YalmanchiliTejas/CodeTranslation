n = int(input())
numbers = list(map(int, input().split()))
result = 0
sum_of_numbers = sum(numbers)
for i in range(n - 1):
    sum_of_numbers -= numbers[i]
    result += numbers[i] * sum_of_numbers
    result %= 1000000007
print(result)