from sys import stdin
lines = stdin.readlines()
 
N, M = map(int, lines[0].split())

if N == M:
  print("Yes")
elif N > M:
  print("No")
elif N < M:
  print("Yes")
