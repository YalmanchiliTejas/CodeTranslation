h, w = map(int, input().split())
a = ''.join([input() for _ in range(h)])
c = ''
b = ''

for i in range(h):
    s = a[i*w:-~i*w]
    if s != '.' * w:
        b += s

nh = len(b) // w
for j in range(w):
    s = b[j::w]
    if s != '.' * nh:
        c += s

nw = len(c) // nh
for i in range(nh):
    print(c[i::nh])
