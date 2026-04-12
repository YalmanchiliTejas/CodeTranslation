def i1():
 return int(input())
def i2():
 return [int(i) for i in input().split()]
n=i1()
x=i2()
z=[]
for i in range(n):
 z.append([x[i],i])
y=sorted(z)
s1=y[n//2-1]
s2=y[n//2]
yy=[0 for i in range(n)]
for i in range(n):
 if i<=n//2-1:
   yy[y[i][1]]=s2
 else:
   yy[y[i][1]]=s1
for i in yy:
 print(i[0])