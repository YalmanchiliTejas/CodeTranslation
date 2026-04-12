N = input()
a_list = [int(i) for i in input().split(' ')]
mod = 1000000007
 
sum = 0
for i in a_list:
  sum += i
 
output_sum = 0
for idx, i in enumerate(a_list[:-1]):
  sum -= a_list[idx]
  output_sum += i*sum
  
print(output_sum%mod)