import re
n = int(input())
s = input()
k = int(input())
x = s[k-1]
print(re.sub('[^' + x + ']', '*', s))