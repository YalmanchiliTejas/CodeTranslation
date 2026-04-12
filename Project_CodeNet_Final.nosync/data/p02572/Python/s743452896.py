N = input()
a_list = [int(i) for i in input().split(' ')]
mod = 1000000007

sum_list = []
sum = 0
for i in a_list:
  sum += i
  sum_list.append(sum)

sum = 0
for idx, i in enumerate(a_list[:-1]):
  sum += i*(sum_list[-1]-sum_list[idx])
  
print(sum%mod)
