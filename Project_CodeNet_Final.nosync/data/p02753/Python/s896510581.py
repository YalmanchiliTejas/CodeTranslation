import sys
input = sys.stdin.readline
S = set(list(input())[: -1])
if len(S) > 1: print("Yes")
else: print("No")