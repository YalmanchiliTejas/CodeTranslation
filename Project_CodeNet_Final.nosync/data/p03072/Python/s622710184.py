n = int(input())
h = [int(xi) for xi in input().split()]

h0 = 0
count = 0
for xi in range(n):
    if h0 <= h[xi]:
        count+=1
        h0=h[xi]

print(count)
