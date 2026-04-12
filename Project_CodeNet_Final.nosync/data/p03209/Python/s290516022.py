n, x = map(int, input().split())
h=[1]*(n+1)
p=[1]*(n+1)
for i in range(1, n+1):
    h[i]=3+h[i-1]*2
for i in range(1, n+1):
    p[i]=p[i-1]*2+1
def f(m, y):
    if m==0:
        return 1
    if y==1:
        return 0
    if y<=h[m-1]+1:
        return f(m-1, y-1)
    if y==h[m-1]+2:
        return p[m-1]+1
    if y<=h[m-1]*2+2:
        return f(m-1, y-h[m-1]-2)+p[m-1]+1
    if y==h[m-1]*2+3:
        return p[m-1]*2+1
print(f(n,x))
