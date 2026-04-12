n = int(input())
num_list = input().split()

mod_value = 10**9 + 7
sum_all = 0
sum_int = 0

for index in range(len(num_list) - 1):
  sum_int += int(num_list[index])
  sum_all += sum_int * int(num_list[index + 1])
  if sum_all > mod_value:
    sum_all %= mod_value

print(sum_all)
