n=int(input())
a=sorted([int(input()) for _ in [0]*n])

if n%2==0:
    print(2*sum(a[n//2+1:])-2*sum(a[:n//2-1])+a[n//2]-a[n//2-1])
else:
    b=abs(sum(a[n//2-1:n//2+1])+2*sum(a[:n//2-1])-2*sum(a[n//2+1:]))
    a.sort(reverse=True)
    c=abs(sum(a[n//2-1:n//2+1])+2*sum(a[:n//2-1])-2*sum(a[n//2+1:]))
    print(max(b,c))