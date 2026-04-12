import sys
input = sys.stdin.readline
S = list(input())[: -1]
if S.count("A") % 3: print("Yes")
else: print("No")