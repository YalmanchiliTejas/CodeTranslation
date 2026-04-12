import sys
n=int(input())
a=list(map(int,input().split()))


if n==2:
    print(max(a))
    sys.exit()

a0=[a[0],a[0]]
a1=[0,a[1]]
a2=[0,0,a[2]]
for i in range(2,n):
    if i%2==0:
        a0.append(a0[i-2]+a[i])
        a1.append(a1[i-1])
        if i>=4: a2.append(max(a2[i-2],a1[i-3],a0[i-4])+a[i])
    else:
        a0.append(a0[i-1])
        a1.append(max(a1[i-2],a0[i-3])+a[i])
        a2.append(a2[i-1])

if n%2==1: print(max(a0[n-1],a1[n-1],a2[n-1]))
else: print(max(a0[n-1],a1[n-1]))