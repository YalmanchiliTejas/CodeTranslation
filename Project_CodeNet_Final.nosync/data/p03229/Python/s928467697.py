a=[]
n=int(input())
for i in range(n):a.append(int(input()))
a.sort()
if len(a)%2==0:
    b=[a.pop(len(a)//2-1)]
    while len(a)!=1:
        b.append(a.pop(-1))
        b.append(a.pop(0))
    b.append(a.pop(-1))
else:
    b=[a.pop(len(a)//2)]
    if abs(b[0]-a[len(a)//2])>abs(b[0]-a[len(a)//2-1]):
        while len(a)!=0:
            b.append(a.pop(-1))
            b.append(a.pop(0))
    else:
        while len(a)!=0:
            b.append(a.pop(0))
            b.append(a.pop(-1))
ans=0
for i in range(n-1):ans+=abs(b[i]-b[i+1])
print(ans)