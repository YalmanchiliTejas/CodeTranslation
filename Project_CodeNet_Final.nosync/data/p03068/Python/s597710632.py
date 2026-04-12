import sys

def I(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LMI(): return list(map(int, sys.stdin.readline().split()))
MOD = 10 ** 9 + 7
INF = float('inf')

N = I()
S = input()
K = I()

c1 = S[K - 1]
for c in S:
    print(c if c == c1 else '*', end='')
print()