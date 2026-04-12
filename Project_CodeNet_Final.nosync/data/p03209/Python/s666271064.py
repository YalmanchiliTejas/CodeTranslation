n,x=map(int,input().split())
a,b=[1],[1]
for i in range(50):
    a.append(a[-1]*2+3)
    b.append(b[-1]*2+1)
def paty(l,u):
    if l==0 and u==1:
        return 1
    if u==1:
        return 0
    elif u<a[l]//2+1:
        return paty(l-1,u-1)
    elif u==a[l]//2+1:
        return b[l-1]+1
    elif u<a[l]:
        return b[l-1]+1+paty(l-1,u-a[l]//2-1)
    else:
        return b[l]
print(paty(n,x))
