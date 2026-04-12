n=int(input())
d=dict()
for i in input():
    if i in d:
        d[i]+=1
    else:
        d[i]=1
#print(d)
for i in range(1,n):
    d1=dict()
    for j in input():
        if j in d1:
            d1[j]+=1
        else:
            d1[j]=1
    d2=dict()
    for k,j in d.items():
        if k in d1:
            d2[k]=min(j,d1[k])
    #print(d1,d2)
    d=d2
#print(d)
s=''
for i,j in sorted(d.items(),key=lambda x:x[0]):
    s+=i*j
print(s)