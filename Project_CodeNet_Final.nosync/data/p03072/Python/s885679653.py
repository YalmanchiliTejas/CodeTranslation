N=int(input())
H=list(map(int,input().split()))
summary=1

for i in range(1,N):
    flag=1
    for j in range(i):
        if H[j]>H[i]:
            flag=0
    if flag==1:
        summary=summary+1

print(summary)        
