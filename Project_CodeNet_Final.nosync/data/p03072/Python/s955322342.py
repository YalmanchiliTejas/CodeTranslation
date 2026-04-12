n = int(input())
a = list(map(int,input().split()))
t = 0
m = a[t]
for x in a:
    if x == m:
        t = t+1
    elif x > m:
        t = t+1
        m = x

print(t)