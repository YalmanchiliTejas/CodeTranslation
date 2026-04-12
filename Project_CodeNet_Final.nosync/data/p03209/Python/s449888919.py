pa = [1]
atu = [1]

for i in range(50):
    pa.append(pa[i]*2+1)
    atu.append(atu[i]*2+3)
    
def f(n,x):
    if x == 1:
        if n == 0:
            return 1
        else:
            return 0
    elif 2 <= x <= atu[n-1]+1:
        return f(n-1,x-1)
    elif x == atu[n-1]+2:
        return pa[n-1]+1
    elif atu[n-1]+3 <= x <= 2*atu[n-1]+2:
        return pa[n-1]+f(n-1,x-atu[n-1]-2)+1
    elif x == 2*atu[n-1]+3:
        return 2*pa[n-1]+1
        
n ,x = map(int,input().split())
print(f(n,x))