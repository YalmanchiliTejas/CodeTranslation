import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def ii(): return int(stdin.readline())
def li(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().rstrip()
N = ii()
S = ns()
K = ii()
sym = S[K-1]

new = [ s if s == sym else "*" for s in S]
print(''.join(new))
