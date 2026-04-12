import sys
readline = sys.stdin.readline
s = set(readline().strip())
if len(s) != 1:
    print("Yes")
else:
    print("No")
