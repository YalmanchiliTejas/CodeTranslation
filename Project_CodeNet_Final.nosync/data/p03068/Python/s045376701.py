import re

n = int(input())
s = input()
k = int(input())

err = s[k-1]
s = re.sub("[^"+err+"]", "*", s)

print(s)