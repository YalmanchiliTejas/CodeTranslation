n=int(input())
h=list(map(int,input().split()))
c=0
for i in range(1,n):
    for j in range(i):
        if h[j]>h[i]:
            break
    else:
        c+=1
print(c+1)