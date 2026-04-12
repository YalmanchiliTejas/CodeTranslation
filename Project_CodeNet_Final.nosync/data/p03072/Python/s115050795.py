n = int(input())
h = list(map(int,input().split()))
high = h[0]
p = 1

for i in range(n)[1:]:
    if high <= h[i]:
        high = h[i]
        p += 1

print(p)