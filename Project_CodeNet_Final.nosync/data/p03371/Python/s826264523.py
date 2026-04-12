import sys,collections;sys.setrecursionlimit(10**7)
def Is(): return [int(x) for x in sys.stdin.readline().split()]
def Ss(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

A,B,C,x,y = Is()
ans = 10**10
for i in range(0,max(x*2,y*2)+3,2):
    a = max(0,(x - i//2)*A)
    b = max(0,(y - i//2)*B)
    c = i*C
    ans = min(a+b+c,ans)
print(ans)