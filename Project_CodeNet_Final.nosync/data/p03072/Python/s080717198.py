n = map(int, input().split())
h = input().split()
h = [int(i) for i in h]

c = 0

if len(h)==1:
    print(1)
else:
    m = h[0]
    for i in h:
        if i>=m:
            c += 1
            m = i

    print(c)

