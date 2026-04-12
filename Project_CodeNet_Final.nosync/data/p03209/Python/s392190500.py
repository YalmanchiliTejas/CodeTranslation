


n, x = (int(x) for x in input().split())

f = [0] * (n+1)
g = [0] * (n+1)
f[0] = 1
g[0] = 1
for i in range(1, n+1):
    f[i] = f[i-1]* 2 + 3
    g[i] = g[i-1]* 2 + 1

total = 0
remain = x

def eat(n):

    global total
    global f
    global remain

    if remain == 0:
        return
    if n < 0:
        return
    if f[n] <= remain:
        total += g[n]
        remain -= f[n]
        return
    if f[n] > remain:
        remain -=1
        if remain == 0:
            return
        if f[n-1] > remain:
            eat(n-1)
        else:
            total += g[n-1]
            remain -= f[n-1]
            if remain == 0:
                return
            total += 1
            remain -= 1
            eat(n-1)

eat(n)
print(total)
