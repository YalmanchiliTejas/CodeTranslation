n,x=map(int,input().split())
def b(j):
    return 2**(j+2)-3
def p(j):
    return 2**(j+1)-1
def f(n,x):
    if n==0:
        return 0 if x<=0 else 1
    elif x<=b(n-1)+1:
        return f(n-1,x-1)
    elif x==b(n-1)+2:
        return p(n-1)+1
    elif 2+b(n-1)<x<=2*b(n-1)+2:
        return p(n-1)+1+f(n-1,x-b(n-1)-2)
    else:
        return 2*p(n-1)+1
print(f(n,x))