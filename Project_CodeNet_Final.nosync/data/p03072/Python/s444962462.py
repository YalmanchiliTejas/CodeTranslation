input()
h = [int(x) for x in input().split()]

maxh = 0
view = 0

for hh in h:
    if hh >= maxh:
        view += 1
        maxh = hh

print(view)