n=int(input())
x=list(map(int,input().split()))
 
l=[x[i] for i in range(n)]
 
l.sort()
 
small=l[n//2-1]
large=l[n//2]
 
for i in range(n):
    if x[i]>=large:
        print(small)
    else:
        print(large)