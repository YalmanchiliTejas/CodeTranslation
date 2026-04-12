from sys import stdin

a,b,c = [int(x) for x in stdin.readline().rstrip().split()]

if int(str(a)+str(b)+str(c))%4 == 0:
    print("YES")
else:
    print("NO")