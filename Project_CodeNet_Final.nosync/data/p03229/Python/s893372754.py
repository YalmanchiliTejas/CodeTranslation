import sys
input=sys.stdin.readline
n=int(input())
a=[int(input())for _ in range(n)]
a.sort()
ans1=0
ans2=0
if n%2:
    for i in range(n):
        if i<n//2:
            ans1-=a[i]*2
        elif i<n//2+2:
            ans1+=a[i]
        else:
            ans1+=a[i]*2
    for i in range(n):
        if i<(n-2)//2:
            ans2-=a[i]*2
        elif i<(n-2)//2+2:
            ans2-=a[i]
        else:
            ans2+=a[i]*2
    print(max(ans1,ans2))

else:
    for i in range(n):
        if i<(n-2)//2:
            ans1-=a[i]*2
        elif i<(n-2)//2+1:
            ans1-=a[i]
        elif i<(n-2)//2+2:
            ans1+=a[i]
        else:
            ans1+=a[i]*2
    print(ans1)
