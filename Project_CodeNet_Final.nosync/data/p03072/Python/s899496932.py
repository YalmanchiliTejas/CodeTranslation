n=int(input())
a=list(map(int,input().split()))
b=[]
count=0
for i in range(n):
    b.append(a[i])
    b=sorted(b)
    if b[i]==a[i]:
        count=count+1
    else:
        pass
print(count)