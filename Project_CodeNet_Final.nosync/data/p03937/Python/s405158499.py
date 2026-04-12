h, w = map(int, input().split())
a1 = []
s = input()
for j in range(w):
    if s[j] == "#":
        a1.append(j)
a =[]
for i in range(h - 1):
    s = input()
    for j in range(w):
        if s[j] == "#":
            a.append(j)
    if a[0] < a1[len(a1) - 1]:
        print("Impossible")
        raise SystemExit
    a1 = [i for i in a]
    a = []
print("Possible")