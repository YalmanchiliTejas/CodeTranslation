import sys

S = list(sys.stdin.readline().strip())
if len(set(S)) > 1:
    print("Yes")
else:
    print("No")