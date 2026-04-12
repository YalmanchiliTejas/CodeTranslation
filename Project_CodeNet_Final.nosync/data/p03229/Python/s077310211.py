from collections import deque
n=int(input())
a=[0]*n
for i in range(n):
    a[i]=int(input())
a.sort()
ans1=0
d1=deque([a[0]])
l1=1
r1=n-1
while l1<=r1:
    d1.appendleft(a[r1])
    r1-=1
    if l1<=r1:
        d1.append(a[r1])
        r1-=1
    if l1<=r1:
        d1.appendleft(a[l1])
        l1+=1
    if l1<=r1:
        d1.append(a[l1])
        l1+=1
d1_l=list(d1)
ans2=0
d2=deque([a[n-1]])
l2=0
r2=n-2
while l2<=r2:
    d2.appendleft(a[l2])
    l2+=1
    if l2<=r2:
        d2.append(a[l2])
        l2+=1
    if l2<=r2:
        d2.appendleft(a[r2])
        r2-=1
    if l2<=r2:
        d2.append(a[r2])
        r2-=1
d2_l=list(d2)
for i in range(n-1):
    ans1+=abs(d1_l[i]-d1_l[i+1])
for i in range(n-1):
    ans2+=abs(d2_l[i]-d2_l[i+1])
print(max(ans1,ans2))
