import re
n = int(input())
s = input()
k = int(input())
s = re.sub(r"[^{}]".format(s[k-1]), '*', s)
print(s)
