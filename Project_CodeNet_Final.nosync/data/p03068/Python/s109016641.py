import re

n = int(input())
s = input()
k = int(input())

r = s[k-1]
print(re.sub('[^'+ r +']', '*', s))
