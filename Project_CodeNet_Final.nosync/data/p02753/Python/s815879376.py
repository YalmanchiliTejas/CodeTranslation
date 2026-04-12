import sys
input = sys.stdin.readline
s=input().strip()
print("No" if len(set(list(s)))==1 else "Yes")
