import re
input()
s = input()
k = s[int(input()) -1]

print(re.sub(r'[^%s]'%k, '*', s))