N = int(input())
a_list = list(map(int, input().split()))
a_list.reverse()

partial_sum = 0
sum_ = 0
for i in range(1, N):
  partial_sum += a_list[i-1]
  sum_ += a_list[i] * partial_sum
  
print(sum_ % (10 ** 9 + 7))