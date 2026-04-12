n = int(input())
h = list(map(int,input().split()))

c = 1
er = h[0]
for i in range(n - 1):
    if er <= h[i+1]:
        er = h[i+1]
        c += 1
print(c)