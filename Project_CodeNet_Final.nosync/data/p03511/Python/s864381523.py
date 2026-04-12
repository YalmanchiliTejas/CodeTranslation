n=int(input())
a=sorted([input()for i in range(2)])
s,t=len(a[0]),len(a[1])
c=[]
for i in range(n):
    if (n-i*t)%s==0:
        c.append(a[0]*((n-i*t)//s)+a[1]*i)
        break
for i in range(n):
    if (n-i*s)%t==0:
        c.append(a[1]*((n-i*s)//t)+a[0]*i)
        break
print(sorted(c)[0])