n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
m=n//2
l=b[m-1]
r=b[m]
for x in a:
    print(l if x>l else r)