a, b, c, x, y = (map(int, input().split()))
candi = []
for i in range(200001):
    candi.append((c*i)+max(0,(x-(i//2)))*a+max(0,(y-(i//2)))*b)
print(min(candi))
