N=int(input())
S=input()
K=int(input())
lists=[]
for i in range(N):
    if S[i]!=S[K-1]:
        lists+="*"
    else:
        lists+=S[i]
print(*lists,sep="")