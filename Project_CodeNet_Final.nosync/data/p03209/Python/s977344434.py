n, x = map(int, input().split())
a = [1]
for i in range(n):
    a.append(a[i] *  2 + 3)
p = [1]
for i in range(n):
    p.append(p[i] * 2 + 1)
    
def f(n,x):
    if n >= 1:
        if x == 1:
            return 0
        elif 1 < x <= 1 + a[n - 1]:
            return f(n-1,x-1)
        elif x == a[n -1] + 2:
            return p[n-1] + 1
        elif a[n-1] + 2 < x <= a[n] - 1:
            return p[n-1] + 1 + f(n-1, x-a[n-1]-2)
        else:
            return p[n]
    if n == 0:
        if x > 0:
            return 1
        else:
            return 0
          
print(f(n,x))