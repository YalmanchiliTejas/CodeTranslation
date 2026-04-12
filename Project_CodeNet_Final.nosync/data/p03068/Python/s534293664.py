from sys import stdin
import re

n = [int(x) for x in stdin.readline().rstrip().split()]
s = stdin.readline().rstrip().split()
s = s[0]
k = [int(x) for x in stdin.readline().rstrip().split()]
k = k[0]

ast = ''
for i in range(len(s)):
    if i+1 == k:
        ast = s[i]

print(re.sub('[^' + ast + ']', '*', s))
