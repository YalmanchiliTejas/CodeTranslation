import sys
input = sys.stdin.readline

S = input().strip()
if len(set(S)) == 1:
    print("No")
else:
    print("Yes")