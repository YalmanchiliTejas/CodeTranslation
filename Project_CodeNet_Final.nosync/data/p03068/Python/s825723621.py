import re
input()
s = input()
l = s[int(input())-1]
pat = '[^{}]'.format(l)
x = re.sub(pat, '*',  s)
print(x)