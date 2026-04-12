import sys
def S(): return sys.stdin.readline().rstrip()
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LS(): return list(sys.stdin.readline().rstrip().split())

A,B,C,X,Y = LI()

only = A*X+B*Y
only_mix = C*max(X,Y)*2
comp = 0
if X > Y:
    comp = C*Y*2+A*(X-Y)
elif X < Y:
    comp = C*X*2+B*(Y-X)
else:
    comp = C*Y*2

print(min(only,only_mix,comp))