N=int(input())
L=list(map(int,input().split()))
i=0
j=0
for n in range(N):
    if L[n]>=j:
        j=L[n]
        i=i+1
print(i)