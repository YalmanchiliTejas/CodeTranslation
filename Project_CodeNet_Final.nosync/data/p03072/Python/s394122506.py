N=int(input())
H=list(map(int,input().split()))

c=1

for i in range(1,N):
    s=0
    for j in range(i):
        if H[j]>H[i]:
            s=1
    if s==0:
        c+=1

print(c)
            
