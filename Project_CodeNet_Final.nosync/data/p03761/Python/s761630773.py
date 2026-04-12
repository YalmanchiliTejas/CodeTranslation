import collections
n = int(input())
dict_same = {}
for i in range(n):
  new_str = input()
  count = collections.Counter(new_str)
  temp_dict = {}
  if i == 0:
    for key, value in count.items():
      dict_same[key] = value
  else:
    same_keys = dict_same.keys() & count.keys()
    for one_keys in same_keys:
      temp_dict[one_keys] = min(dict_same[one_keys], count[one_keys])
    dict_same = temp_dict

sorted_dict = sorted(dict_same.items(), key=lambda x:x[0])
result = ""
for one_str, num in sorted_dict:
  result += one_str * num
print(result)