N=int(input())
S=input()
K=int(input())
#A,B,C=map(int,input().split())
#A=list(map(int,input().split()))
T=""
for i in S:
    if i!=S[K-1]:
        T+="*"
    else:
        T+=S[K-1]
print(T)
