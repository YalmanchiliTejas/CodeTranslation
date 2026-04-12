
N = int(input())
h = map(int,input().split())
H = []
for c in h:
    H.append(int(c))

count = 0
maxH = 0
for i in range(N):
    if H[i] >= maxH:
        count = count + 1
        maxH = H[i]

print(count)