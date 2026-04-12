import re
l = int(input())
ss = input()
n = int(input())-1
s = ss[n]
print(re.sub('[^%s]' % s, '*', ss))

