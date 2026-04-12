from sys import stdin
r,g,b = [int(x) for x in stdin.readline().rstrip().split()]
a = 100*r+10*g+b
if a%4 == 0:
    print("YES")
else:
    print("NO")
