import re
n = input()
s = input()
k = int(input())
tmp = re.sub(r'[a-z]', "*", s.replace(s[k-1], "0"))
print(tmp.replace("0", s[k-1]))