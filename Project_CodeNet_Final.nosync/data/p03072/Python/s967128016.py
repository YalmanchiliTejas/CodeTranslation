n=int(input())
h=list(map(int,input().split()))
c=0

for i in range(n):
    f=True
    for j in range(i):
        if h[j]>h[i]:
            f=False
    if f:
        c+=1
print(c)
