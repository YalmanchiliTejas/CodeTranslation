num = int(input())
array = list(map(int,input().split()))
num_sum = 0
tmp_sum = 0

tmp_sum = sum(array)

for a in array:
      tmp_sum -= a
      num_sum += tmp_sum*a

print(num_sum % 1000000007)