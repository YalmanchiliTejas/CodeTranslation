
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    N=I()
    S=list(input())
    K=I()
    K-=1
    s=S[K]
    for i in range(N):
        if S[i]!=s:
            S[i]="*"
            
    print(''.join(map(str, S)))

main()
