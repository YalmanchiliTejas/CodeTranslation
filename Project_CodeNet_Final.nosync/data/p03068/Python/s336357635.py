import re

n = int(input())
s = input()
k = int(input())

p = '[^' + s[k-1] + ']'
print(re.sub(p, '*', s))