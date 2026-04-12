import itertools
import sys

s = input()
ok = False
for i in range(len(s) - 1):
    if (s[i] == 'A' and s[i + 1] == 'C'):
        ok = True

if ok:
    print("Yes")
else:
    print("No")
