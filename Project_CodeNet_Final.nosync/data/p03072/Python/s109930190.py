n=int(input())
D=list(map(int,input().split()))
c=1
for i in range(1,n):
    if max(D[j] for j in range(i))<=D[i]:
        c+=1
print(c)