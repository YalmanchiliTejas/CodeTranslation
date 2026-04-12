import re
n = int(input())
s = input()
k = int(input())
#print(s.replace(s[k-1], "*"))
print(re.sub('[^{}]'.format(s[k-1]), "*", s))
