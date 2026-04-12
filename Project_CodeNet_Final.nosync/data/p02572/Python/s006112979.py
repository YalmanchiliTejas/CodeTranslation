n = int(input())
numbers = list(map(lambda x: int(x), input().split()))

sum_n = sum(numbers)
total_value = 0

for current_num in numbers:
    sum_n -= current_num
    total_value += current_num * sum_n
#     print(sum_n, total_value, current_num)

print(total_value % (10**9+7))