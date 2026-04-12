n = int(input())
x = list(map(int,input().split()))
y = sorted(x)
m = (y[n//2-1]+y[n//2])/2
for i in x:
    if i<m:
        print(y[n//2])
    else:
        print(y[n//2-1])
