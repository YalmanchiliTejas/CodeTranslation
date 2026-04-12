from sys import stdin
ans = 'NO'
r,g,b = map(int,stdin.readline().split())
if (r*100 + g *10 + b) %4==0:
 ans = 'YES'
print ans