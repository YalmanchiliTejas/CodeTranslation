import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():

    n=int(input())
    s=list(input())
    k=int(input())
    val=s[k-1]
    for i in range(n):
        if s[i]!=val:
            s[i]='*'
    print(''.join(s))


resolve()