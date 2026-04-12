import re

n = int(input())
s = input()
k = int(input())

target = s[k-1]
print(re.sub('[^' + s[k-1] + ']', '*', s))