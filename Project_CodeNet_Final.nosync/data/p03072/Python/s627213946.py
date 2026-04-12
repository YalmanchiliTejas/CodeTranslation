n=int(input())
a=input().split()
for j in range(n):
    a[j]=int(a[j])
m=[]
m.append(a[0])
for k in range(n-1):
    x=max(m)
    if x<=a[k+1]:
        m.append(a[k+1])
print(len(m))