n,t,e=map(int,input().split())
x=list(map(int,input().split()))
s=-1
for i in range(n):
    for j in range(x[i],20000,x[i]):
        if t-e<=j<=t+e:
            s=i+1
            break
print(s)
