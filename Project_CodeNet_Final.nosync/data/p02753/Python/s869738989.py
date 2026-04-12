import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

s = input()
for i in range(2):
  if s[i] != s[i+1]:
    count += 1
print("Yes" if count >= 1 else "No")