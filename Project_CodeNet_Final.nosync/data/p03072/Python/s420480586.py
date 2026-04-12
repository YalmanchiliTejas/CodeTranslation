N = int(input())
H = list(map(int, input().split()))
result = 1
h = H[0]

for i, h1 in enumerate(H):
    if i < len(H)-1:
        h2 = H[i+1]
    else:
        break
    if h <= h2 and h1 <= h2:
        h = h2
        result += 1

print(result)