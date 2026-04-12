n = int(input())
a = list(map(int, input().split()))


ruiseki0 = [0] * (n + 10) 
for i in range(n):
    ruiseki0[i + 1] = ruiseki0[i]
    if i % 2 == 0:
        ruiseki0[i + 1] += a[i]
        
l = [0] * (n + 1)
for i in range(n + 1):
    l[i] = ruiseki0[i]
    if i % 2 == 0:
        if i == 0:
            l[i] = 0
        else:
            l[i] = max(l[i - 2] + a[i - 1], l[i])


a = a[::-1]
ruiseki0 = [0] * (n + 10) 
for i in range(n):
    ruiseki0[i + 1] = ruiseki0[i]
    if i % 2 == 0:
        ruiseki0[i + 1] += a[i]

r = [0] * (n + 1)
for i in range(n + 1):
    r[i] = ruiseki0[i]
    if i % 2 == 0:
        if i == 0:
            r[i] = 0
        else:
            r[i] = max(r[i - 2] + a[i - 1], r[i])
   
ans = - 10 ** 20
for i in range(n):
    if n - i - 2 < 0:
        break
    if n % 2 == 0 and i % 2 == 0:
        continue
    ans = max(ans, l[i] + r[n - i - 2])
    
if n % 2 == 0:
    ans1 = 0
    ans2 = 0
    for i in range(n):
        if i % 2 == 0:
            ans1 += a[i]
        else:
            ans2 += a[i]
    ans = max(ans1, ans2, ans)
if n % 2 == 1:
    ans = max(ans, sum(a)- ruiseki0[n])
print(ans)