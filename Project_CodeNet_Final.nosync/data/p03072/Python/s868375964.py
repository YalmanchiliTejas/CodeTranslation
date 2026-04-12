n = int(input())

h = list(map(int, input().split()))
s = 1

max = h[0]

for i in range(1,n):
    if max <= h[i]:
        max = h[i]
        s += 1

print(s)
