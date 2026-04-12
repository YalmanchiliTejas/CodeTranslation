N=int(input())
S=list(input())
K=int(input())
count=0
x=len(S)
for i in range(0,x):
    if(S[i]!=S[K-1]):
        count=count+1
        S[i]="*"
print("".join(S))
