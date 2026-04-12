n = int(input())
h = list(map(int,input().split()))
m = h[0]
c = 1
for i in range(1,n):
    if m <= h[i]:
        c += 1
    m = max(m,h[i])
print(c)