import re
n = int(input())
s = input()
k = int(input())
s = re.sub('[^%s]' % s[k-1], '*', s)
print(s)
