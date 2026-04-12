n=int(input())
l=list(map(int,input().split()))
x,y=[],[]
for i in range(n):
    if(i%2==0):
        y.append(l[i])
    else:
        x.append(l[i])
if(n%2==0):
    print(*(x[::-1]+y))
else:
    print(*(y[::-1]+x))
