import itertools

n = int(input())
num_list = input().split()

mod_base = 10 ** 9 + 7

num_list = [int(x) for x in num_list]

sum_list = []
sum_tmp = sum(num_list)
for i in range(len(num_list)):
    sum_list.append(sum_tmp)
    sum_tmp -= num_list[i]

all_sum = 0
for index, num in enumerate(num_list):
    if index + 1 >= len(num_list):
        break
    all_sum += num * sum_list[index+1]

print(all_sum % mod_base)