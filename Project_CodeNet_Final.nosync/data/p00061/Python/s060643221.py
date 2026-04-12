
c = []
d = {}
while True:
    a,b = map(int, input().split(','))
    c += [b]
    d[a] = b
    if a == 0 : break
c = sorted(set(c))[::-1]
while True:
    try:print(c.index(d[int(input())])+1)
    except: break


