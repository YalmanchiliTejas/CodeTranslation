n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
a=sorted(a)
from collections import deque

if n%2==0:
    front=a[:n//2]
    rear=a[n//2:]
    f1=deque(front)
    f2=deque(front)
    r1=deque(rear)
    r2=deque(rear)
    ans1=0
    ans2=0
    for i in range(n):
        #print(f1,f2,r1,r2)
        if i==0:
            last1=f1.pop()
            last2=r2.popleft()
        elif i%2==1:
            now1=r1.pop()
            now2=f2.popleft()
            ans1+=abs(last1-now1)
            ans2+=abs(last2-now2)
            last1=now1
            last2=now2
        elif i%2==0:
            now1=f1.popleft()
            now2=r2.pop()
            ans1+=abs(last1-now1)
            ans2+=abs(last2-now2)
            last1=now1
            last2=now2
    print(max(ans1,ans2))
else:
    med=a[n//2]
    front=a[:n//2]
    rear=a[n//2+1:]
    f1=deque(front)
    f2=deque(front)
    r1=deque(rear)
    r2=deque(rear)
    ans1=0
    ans2=0
    for i in range(n):
        #print(f1,f2,r1,r2)
        if i==0:
            last1=med
            last2=med
        elif i%2==1:
            now1=r1.pop()
            now2=f2.popleft()
            ans1+=abs(last1-now1)
            ans2+=abs(last2-now2)
            last1=now1
            last2=now2
        elif i%2==0:
            now1=f1.popleft()
            now2=r2.pop()
            ans1+=abs(last1-now1)
            ans2+=abs(last2-now2)
            last1=now1
            last2=now2
    print(max(ans1,ans2))