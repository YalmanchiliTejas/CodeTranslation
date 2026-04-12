from sys import stdin
N = list((stdin.readline().strip()))
if N[0]!=N[1] or N[1]!=N[2]:print("Yes")
else:print("No")