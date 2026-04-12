n=int(input())
a=[0]*n
for i in range(n):
    a[i]=int(input())
a.sort()
k=n//2
if n%2==1:
    ans_1 = 2*sum(a[k+1:]) - 2*sum(a[:k+1]) + a[k-1]+a[k]
    ans_2 = 2*sum(a[k:])   - 2*sum(a[:k])   -(a[k]+a[k+1])
    print(max(ans_1,ans_2))
else:
    ans = 2*sum(a[k:])   - 2*sum(a[:k]) -a[k]+a[k-1]
    print(ans)