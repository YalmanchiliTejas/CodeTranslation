from sys import stdin
import re

n = int(stdin.readline().rstrip())
s = stdin.readline().rstrip()
k = int(stdin.readline().rstrip())

c = "[^"+s[k-1]+"]"

ans = re.sub(c, '*', s)

print(ans)