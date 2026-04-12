n=int(input())
h=input().split()
for i in range(n):
    h[i]=int(h[i])
ans=1
x=[]
x.append(h[0])
for j in range(1,n):
    if h[j]>=max(x):
        ans+=1
    x.append(h[j])
print(ans)
