N,X = map(int,input().split())
p=[0]*(N+1)
num=[0]*(N+1)
for i in range(N+1):
    p[i] = 2**(i+1)-1
for i in range(N+1):
    num[i] = 2**(i+2)-3
def f(L,x):
    if L == 0:
        return 0 if x<=0 else 1
    elif x < ((2**(L+2)-4)//2+1):
        return f(L-1,x-1)
    else:
        return p[L-1]+1+f(L-1,x-2-num[L-1])

print(f(N,X))
