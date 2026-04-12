import sys
import math 

n = int(raw_input().strip())
inp = map(int, raw_input().strip().split(" "))
max = 0
ans = 0

for h in inp:
    if max <= h:
        max = h
        ans += 1

print(ans)