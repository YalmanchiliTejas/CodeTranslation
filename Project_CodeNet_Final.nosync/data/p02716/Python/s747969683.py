import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
printV = lambda x: print(*x, sep="\n")
printH = lambda x: print(" ".join(map(str,x)))
def IS(): return sys.stdin.readline()[:-1]
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LI1(): return list(map(int1, sys.stdin.readline().split()))
def LII(rows_number): return [II() for _ in range(rows_number)]
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def LLI1(rows_number): return [LI1() for _ in range(rows_number)]

def main():
	n = II()
	a = LI()
	a = [0]+a
	dp_t = defaultdict(lambda: -10**18)
	dp_f =  defaultdict(lambda: -10**18)
	dp_f[(0,0)]=0
	for i in range(1,n+1):
		dp_f[(i,(i-1)//2)]=max(dp_f[(i-1,(i-1)//2)], dp_t[(i-1,(i-1)//2)])
		dp_t[(i,(i-1)//2)]=dp_f[(i-1,(i-1)//2-1)]+a[i]
		dp_f[(i,(i-1)//2+1)]=max(dp_f[(i-1,(i-1)//2+1)], dp_t[(i-1,(i-1)//2+1)])
		dp_t[(i,(i-1)//2+1)]=dp_f[(i-1,(i-1)//2)]+a[i]
	print(max(dp_t[(n,n//2)],dp_f[(n,n//2)]))
if __name__ == '__main__':
	main()