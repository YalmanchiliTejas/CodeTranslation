N = int(input())
A = list(map(int, input().split()))

num_sum = 0
temp_sum_num = sum(A)

for i in range(N - 1):
    temp_sum_num -= A[i]
    num_sum += A[i] * temp_sum_num


num_sum = num_sum % (10 ** 9 + 7)

print(num_sum)
