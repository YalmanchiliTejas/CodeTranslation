n = int(input())
a = list(map(int,input().split()))
t = 0
m = a[0]
for x in a:
    if x == m:
        t += 1
    elif x > m:
        t += 1
        m = x

print(t)