from sys import stdin
X,Y,Z=[int(x) for x in stdin.readline().rstrip().split()]
ans = (X-Z) // (Y+Z)
print(ans)