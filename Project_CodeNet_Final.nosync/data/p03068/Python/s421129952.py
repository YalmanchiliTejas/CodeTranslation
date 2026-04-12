N=int(input())
ls_S=list(input())
K=int(input())

for i in range(N):
    if ls_S[i]!=ls_S[K-1]:
        ls_S[i]="*"
for s in ls_S:
    print(s,end = "")
    
