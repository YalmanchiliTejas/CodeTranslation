n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
a.sort()
ans = 0
l=0
r=0

if(n%2==1):
    tmp1=-1*a[int(n/2)-1]-a[int(n/2)]
    tmp2=a[int(n/2)]+a[int(n/2)+1]
    for i in range(int(n/2)):
        tmp1 += 2*a[-i-1]
        tmp2 += -2*a[i]
    for i in range(int(n/2)-1):
        tmp1 += -2*a[i]
        tmp2 += 2*a[-i-1]
    if(tmp1>tmp2):
        print(tmp1)
    else:
        print(tmp2)
    
else:
    tmp1=a[int(n/2)]-a[int(n/2)-1]
    for i in range(int(n/2)-1):
        tmp1+=-2*a[i]+2*a[int(n/2)+i+1]
    print(tmp1)
