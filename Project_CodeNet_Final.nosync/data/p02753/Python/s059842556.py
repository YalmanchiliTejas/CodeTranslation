import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    s = str(input())
    if len(set(s))==1:
        print('No')
    else:
        print('Yes')
    
    
resolve()