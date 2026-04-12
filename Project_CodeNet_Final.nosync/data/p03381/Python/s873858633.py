n = int(input())
x= list(map(int, input().split()))
sx=sorted(x)
center=sum(sx[n//2-1:n//2+1])/2
under=sx[n//2-1]
over=sx[n//2]
for i in x:
    if i>=center:
        print(under)
    else:
        print(over)