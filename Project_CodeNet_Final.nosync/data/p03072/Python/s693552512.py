n=int(input())
h=list(map(int,input().split()))
c=n
for i in range(n):
    for j in range(i):
        if h[j]>h[i]:
            c-=1
            break
print(c)
