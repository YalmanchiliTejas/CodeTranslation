import re

_ = int(input())
s = input()
k = int(input())

k_char = s[k-1]
print(re.sub('[a-z]', '*', s.replace(k_char, '-')).replace('-', k_char))