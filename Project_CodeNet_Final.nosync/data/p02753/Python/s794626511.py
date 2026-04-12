import sys
stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)

def LI(): return list(map(int, stdin.readline().split()))
def LS(): return list(stdin.readline())

s = LS()
if 'A' in s:
    if 'B' in s:
        print('Yes')
        exit()
print('No')