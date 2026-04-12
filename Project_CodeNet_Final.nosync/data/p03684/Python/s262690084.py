n = input()
R = range(n)
P = [map(int,raw_input().split())+[i]for i in R]

a = range(n)
def root(x):
    if x != a[x]:a[x]=x=root(a[x])
    return x
def unite(x, y):
    x=root(x);y=root(y)
    a[max(x,y)]=min(x,y)
Q=[]
def s(i):
    P.sort(key=lambda x:x[i])
    for j in R[:-1]:
        Q.append((P[j+1][i] - P[j][i], P[j][2], P[j+1][2]))
s(0);s(1);Q.sort()
ans = 0
for w,x,y in Q:
    if root(x)!=root(y):
        ans += w
        unite(x, y)
print ans
