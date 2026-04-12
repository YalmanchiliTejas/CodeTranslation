def umi(n,a):
    ii=1 
    for i in range(1,n):
        if a[i]>=max(a[:i]):
            ii += 1
    return ii
n=int(input())
a=list(map(int,input().split()))
print(umi(n,a))