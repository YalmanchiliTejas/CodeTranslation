n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
a.sort()
a.reverse()
sum=0
if n%2==1:
    sum1=0
    sum2=0
    for j in range(n):
        if j+1<=n//2:
            sum1+=a[j]*2
        elif j+1<=n//2+2:
            sum1-=a[j]
        else:
            sum1-=a[j]*2
    a.reverse()
    for j in range(n):
        if j+1<=n//2:
            sum2-=a[j]*2
        elif j+1<=n//2+2:
            sum2+=a[j]
        else:
            sum2+=a[j]*2
    sum=max(sum1,sum2)
else:
    for j in range(n):
        if j+1<=n//2-1:
            sum+=a[j]*2
        elif j+1==n//2:
            sum+=a[j]
        elif j+1==n//2+1:
            sum-=a[j]
        else:
            sum-=a[j]*2
print(sum)