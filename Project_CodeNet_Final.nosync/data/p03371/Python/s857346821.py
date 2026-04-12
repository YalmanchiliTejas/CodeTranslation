A, B, C, X, Y = map(int, input().split())

anset = set()
for i in range(0, max(X, Y)+1):
    anset.add(i*2*C + max(0, X-i)*A + max(0, Y-i)*B)

print(min(anset))