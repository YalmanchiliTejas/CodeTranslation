h,w=map(int,input().split())
a=[s for s in [input() for i in range(h)] if "#" in s]
l=[]
for i in range(w):
    if all([a[k][i]=="." for k in range(len(a))]):
        l.append(i)
for i in l[::-1]:
    for j in range(len(a)):
       a[j]=a[j][:i]+a[j][i+1:]
for i in range(len(a)):
    print(a[i])


