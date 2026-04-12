import re
n = int(input())
s = input()
k = int(input())

res = re.sub('[^'+s[k-1]+']', '*', s)
print(res)