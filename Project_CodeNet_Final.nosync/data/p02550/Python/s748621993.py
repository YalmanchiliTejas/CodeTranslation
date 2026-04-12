n, x, m = map(int, input().split())
a = [-1]*10**5; a[x%m] == 0; b = [x%m]
for i in range(1, n):
    x = x**2%m
    if a[x%m] == -1:
        a[x%m] = i; b.append(b[-1]+x%m)
    else:
        s = a[x%m]-1; g = i-1
        print((b[g]-b[s])*((n-s-1)//(g-s))+b[s+(n-s-1)%(g-s)])
        break
else: print(b[-1])