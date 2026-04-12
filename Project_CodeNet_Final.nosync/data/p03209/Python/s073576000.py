n, x = map(int, input().split())

l = [1]
p = [1]

for i in range(1,n+1):
    l.append(2 * l[i-1] + 3)
    p.append(2 * p[i-1] + 1)

def result(n, x):
    if n == 0:
        if x == 1:
            return 1
        else:
            return 0
    elif x == 1:
        return 0
    
    elif l[n] == x:
        return p[n]
    
    elif l[n]//2 + 1 <= x:
        return p[n-1] + 1 + result(n-1, x - l[n]//2-1)
    else:
        return result(n-1, x-1)

print(result(n, x))