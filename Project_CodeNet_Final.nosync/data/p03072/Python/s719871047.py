n = int(input())
h = list(map(int, input().split()))

out = 1
max = h[0]
for i in range(n-1):
    if h[i+1] >= max:
        max = h[i+1]
        out += 1
print(out)