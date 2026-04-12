import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    n=int(input())
    l=list(map(int,input().split()))
    cnt=1
    for i in range(1,n):
        if l[i]==max(l[:i+1]):
            cnt+=1
    print(cnt)
resolve()