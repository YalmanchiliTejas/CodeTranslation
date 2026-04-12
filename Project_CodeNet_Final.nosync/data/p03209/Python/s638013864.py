n,x = map(int,input().split())

# a : レベルlでの長さ
# p : レベルlでのP数
a,p = [1], [1]
for i in range(n):
    a.append(2*a[-1]+3)
    p.append(2*p[-1]+1)

# f(l,x) : レベルlでの下からxまでのP数
def f(l, x):
    if l==0:
        if x>0:
            return 1
        else:
            return 0
    
    elif x<=a[l-1]+1:
        return f(l-1, x-1)

    else:
        return p[l-1] + 1 + f(l-1, x-a[l-1]-2)

print(f(n,x))