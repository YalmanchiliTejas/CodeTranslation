N = int(input())
num_list = list(map(int, input().split()))
mod = 10**9 + 7

sum_num = 0
sum_list = []
for num in num_list:
  sum_num += num
  sum_num = sum_num % mod
  sum_list.append(sum_num)

answer = 0
for i in range(N):
  sum_num -= num_list[i]
  sum_num = sum_num if sum_num >= 0 else sum_num + mod
  answer += num_list [i] * sum_num
  answer = answer % mod

print(answer)