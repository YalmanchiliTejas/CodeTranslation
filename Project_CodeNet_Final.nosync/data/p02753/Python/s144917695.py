from sys import stdin
S = (stdin.readline().rstrip())
if len(set(list(S))) == 1:
    print("No")
else:
    print("Yes")