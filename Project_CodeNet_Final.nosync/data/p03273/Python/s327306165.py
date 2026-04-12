h, w = map(int, input().split())
ma = []
s = 0
for i in range(h):
    k = []
    k += input()
    if k.count("#") != 0:
        ma.append(k)
        s += 1
q = []
for i in range(w):
    for j in range(s):
        if ma[j][i] == "#":
            break
    else:
        q.append(i)
for i in range(len(q)):
    for j in range(s):
        del ma[j][q[-(i+1)]]
for i in range(s):
    print("".join(ma[i]))