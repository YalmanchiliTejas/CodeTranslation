import sys
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
H,W = LI()
a = [S() for _ in range(H)]
a2,a3 = [],[]
for x in a:
    if '#' in x:
        a2.append(x)
for y in zip(*a2):
    if '#' in y:
        a3.append(y)
for z in zip(*a3):
    print(*z,sep='')
