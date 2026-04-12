import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

md=10**9+7
n=II()
aa=LI()
s=pow(sum(aa),2,md)
for a in aa:
    s-=a**2
    s%=md
inv2=pow(2,md-2,md)
s=s*inv2%md
print(s)
