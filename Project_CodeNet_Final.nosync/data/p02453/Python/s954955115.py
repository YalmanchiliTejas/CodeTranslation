import bisect
n=int(input())
a=list(map(int, input().split()))
q=int(input())
for i in range(q):
    k=int(input())
    if a[0]>k:
        print(0)
    elif k>a[n-1]:
        print(n)
    else:
        L = bisect.bisect_left(a,k)
        print(L)  
