a, b, c, x, y = map(int, input().split())

cand = []
for i in range(max(x, y)+1):
    cand.append(i*2*c + max(0, x-i)*a + max(0, y-i)*b)
print(min(cand))
