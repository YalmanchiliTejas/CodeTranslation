import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    H,W=map(int,input().split())
    A=[]
    for i in range(H):
        a=input()
        if a!='.'*W:
            A.append(a)
    ans=[[] for _ in range(len(A))]
    for i in range(W):
        f=False
        for j in range(len(A)):
            if A[j][i]=='#':
                f=True
                break
        if f:
            for j in range(len(A)):
                ans[j]+=A[j][i]
    for x in ans:
        print(''.join(x))

if __name__ == '__main__':
    main()
