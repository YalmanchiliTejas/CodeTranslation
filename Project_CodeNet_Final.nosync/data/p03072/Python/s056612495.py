n = input()

h = input()
h = h.split(' ')
h = [int(a) for a in h]

r = 0
max = h[0]
for tmp in h:
    if max <= tmp:
        r += 1
        max = tmp

print(r)
