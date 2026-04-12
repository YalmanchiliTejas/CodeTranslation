import sys

def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

A,B,C,X,Y = LI()

ave = (A+B)/2
cost = 0
if ave > C:
    cost += C * min(X,Y) * 2
    if X > Y:
        if A > C * 2:
            cost += C*2*(X-Y)
        else:
            cost += A*(X-Y)
    elif X < Y:
        if B > C * 2:
            cost += C*2*(Y-X)
        else:
            cost += B*(Y-X)
else:
    cost += A*X + B*Y

print(cost)