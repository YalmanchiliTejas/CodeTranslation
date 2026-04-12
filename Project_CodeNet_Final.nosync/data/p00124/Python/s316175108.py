f=0
while 1:
    a={}
    n=int(input())
    if n==0:break
    if f:print()
    f=1
    for i in range(n):
        b=input().split()
        a[b[0]]=[int(b[1])*3+int(b[3]),-i]
    for y,z in sorted(a.items(),key=lambda x:x[1])[::-1]:
        print('%s,%d'%(y,z[0]))