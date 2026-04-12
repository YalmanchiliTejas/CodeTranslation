n=int(input())
h=list(map(int,input().split()))
x=0
for i in range(1,n):
    for j in range(i):
        if h[j]>h[i]:
            x+=1
            break
print(n-x)