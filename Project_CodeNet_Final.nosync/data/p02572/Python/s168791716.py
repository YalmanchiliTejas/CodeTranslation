import itertools
import math

N = int(input())
a_list = list(map(int, input().split()))
a_accumulate = list(itertools.accumulate(a_list))
a_sum = sum(a_list)
result = 0
i = 0
for a in a_list:
  result += a * (a_sum - a_accumulate[i])
  i += 1
print(result%(pow(10,9)+7))