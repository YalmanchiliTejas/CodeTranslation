n=int(input())
h=list(map(int,input().split()))
m=0
for i in range(n):
    f=True
    for j in range(i):
        if h[j]>h[i]:
            f=False
            break

    if f:
        m+=1
print(m)
