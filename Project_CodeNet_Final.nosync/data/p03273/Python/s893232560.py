def rotated(a):
    b = []
    for i in range(len(a[0])):
        b.append("")
        for j in range(len(a)):
            b[-1] += a[j][i]
    return b

H, W = map(int, input().split())
a = []

for i in range(H):
    ai = input()
    if "#" in ai:
        a.append(ai)

a = rotated(a)

for i in range(len(a) - 1, -1, -1):
    if "#" not in a[i]:
        a.remove(a[i])

a = rotated(a)

print("\n".join(a))