N=int(input())
H=list(map(int,input().split()))

Hmax=0
R=0
for Hi in H:
    if Hmax<=Hi:
        R+=1
        Hmax=Hi

print(R)