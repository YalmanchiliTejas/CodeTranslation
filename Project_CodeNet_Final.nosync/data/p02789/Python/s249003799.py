import sys
stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)

def LI(): return list(map(int, stdin.readline().split()))
def LS(): return list(stdin.readline())

n,m = LI()
print('Yes' if n==m else 'No')