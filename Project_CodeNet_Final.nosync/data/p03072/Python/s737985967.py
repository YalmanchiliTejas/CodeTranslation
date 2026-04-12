N = int(input())
H = [ int(n) for n in input().split() ]

count = 1
bounds = H[0]

for i in range(1, N):
    if H[i] >= bounds:
        count += 1
        bounds = H[i]

print(count)