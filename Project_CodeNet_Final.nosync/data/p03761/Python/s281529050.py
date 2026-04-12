import sys
input = sys.stdin.readline
from collections import Counter
import string

n = int(input())
m = []
for _ in range(n):
    m.append(Counter(input().rstrip("\r\n")))
ans = ""
for c in string.ascii_lowercase:
    is_ans = True
    count = 0
    for mi in m:
        if mi.get(c) == None:
            is_ans=False
            break
        count = mi.get(c) if count == 0 else min(count,mi.get(c))
    if is_ans:ans+=c*count
print(ans)