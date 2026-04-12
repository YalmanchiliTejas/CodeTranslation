n, x = input().split()
n, x = int(n), int(x)

a = [1]
for i in range(n):
    a.append(a[i] * 2 + 3)
 
p = [1]
for i in range(n):
    p.append(p[i] * 2 + 1)
 
def solve(n, x):
    if n == 0:
        if x <= 0:
            return 0
        else:
            return 1
    elif x == 1:
        return 0
    elif 1 <  x <=  1 + a[n - 1]:
        return solve(n - 1, x - 1)
    elif x == 2 + a[n-1]:
        return p[n-1] + 1
    elif 2 + a[n-1] < x and x <= 2 + 2 * a[n-1]:
        return solve(n - 1, x - 2 - a[n - 1]) + p[n-1] + 1
    elif x == 3 + 2 * a[n - 1]:
        return 2 * p[n-1] + 1
 
print(solve(n, x))