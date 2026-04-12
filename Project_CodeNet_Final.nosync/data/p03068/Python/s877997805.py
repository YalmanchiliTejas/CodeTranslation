import re

n = int(input())
s = input()
k = int(input())

keychar = s[k-1]
mask = "*"
mask2 = "1"

masked = re.sub(r'%s'%keychar, mask2, s)
masked = re.sub(r'[a-z]', mask, masked)
masked = re.sub(r'%s'%mask2, keychar, masked)
print(masked)
