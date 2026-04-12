import string
from collections import defaultdict

n = int(input())
s_list = [input() for i in range(n)]

alphabet = string.ascii_lowercase
count_dict = defaultdict(int)

for c in alphabet:
  min_count = float("inf")
  for s in s_list:
    count = s.count(c)
    min_count = min(min_count, count)
    count_dict[c] = min_count

final_string = ''

for k, v in count_dict.items():
  if v == 0:
    continue
  else:
    final_string += k * v

final_string_list = list(final_string)
final_string_list.sort()
    
final_string = ''.join(final_string_list)

print(final_string)

