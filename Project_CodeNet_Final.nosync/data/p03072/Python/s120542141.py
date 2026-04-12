a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = []
for i in range(len(b)):
    c = False
    for j in range(i):
        if b[i] < b[j]:
            c = True
    if c == False:
        d.append(i+1)

print(len(d))

