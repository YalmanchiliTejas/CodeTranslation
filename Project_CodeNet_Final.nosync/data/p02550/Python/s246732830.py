N,X,M=map(int, input().split())
m=[0]*M
t={}

def f(x,y):
    return x*x % y
a = X
s=0
for i in range(N):
    if a in t:
        x = t[a]
        nn = N - x
        q,r = divmod(nn,i-x)
        s = m[x-1] + (m[i-1] - m[x-1])*q + m[x-1+r] - m[x-1]
        break
    t[a]=i
    s += a
    m[i] = s
    a = f(a,M)
print(s)