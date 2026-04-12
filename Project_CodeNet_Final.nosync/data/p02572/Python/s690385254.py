N = int(input())
int_list = list(map(int, input().split()))

sum_num = 0
sum_temp = sum(int_list[1:])

for i in range(N-1):
  sum_num += int_list[i] * sum_temp
  sum_temp -= int_list[i+1]
    
print(sum_num % (10 ** 9 + 7))