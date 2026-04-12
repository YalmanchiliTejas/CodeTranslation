import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    n=int(input())
    s=list(input())
    k=int(input())
    l=['*']*n
    for i in range(n):
        if s[i]==s[k-1]:
            l[i]=s[k-1]
    print(''.join(l))
resolve()