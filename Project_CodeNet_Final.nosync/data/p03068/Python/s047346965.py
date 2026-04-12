import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    n=int(input())
    s=input()
    k=int(input())
    l=[]
    for i in range(n):
        if s[i]==s[k-1]:
            l.append(s[k-1])
        else:
            l.append('*')
    print(''.join(l))
resolve()