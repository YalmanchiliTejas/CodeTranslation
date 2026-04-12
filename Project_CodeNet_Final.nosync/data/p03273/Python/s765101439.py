h, w = map(int, input().split())
a = []
for i in range(h):
    a.append(list(input()))
for i in range(h - 1, -1, -1):
    if a[i] == ["."] * w:
        del a[i]
for i in range(w - 1, -1, -1):
    if [a[j][i] for j in range(len(a))] == ["."] * len(a):
        for j in range(len(a)):
            del a[j][i]
for i in range(len(a)):
    print("".join(a[i]))