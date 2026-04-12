n,x = map(int,input().split())
a = [1]
p = [1]
for i in range(n):
    a.append(2*a[i]+3)
    p.append(2*p[i]+1)
def f(n,x):
    if x == 1:
        return int(n <= 0)
    elif 1 < x <= a[n-1]+1:
        return f(n-1,x-1)
    elif x == 2 + a[n-1]:
        return 1+p[n-1]
    elif 2 + a[n-1] < x <= 2+2*a[n-1]:
        return p[n-1]+1+f(n-1,x-2-a[n-1])
    elif x == 2*a[n-1]+3:
        return 2*p[n-1]+1

print(f(n,x))