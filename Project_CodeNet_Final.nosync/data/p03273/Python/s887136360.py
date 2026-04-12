h, w = map(int, input().split())
mass = [input() for _ in range(h)]
for i in reversed(range(h)):
    if mass[i].count("#") == 0:
        mass = mass[:i] + mass[i+1:]

for i in reversed(range(w)):
    cnt = 0
    for row in mass:
        if row[i] == "#":
            cnt += 1
    if cnt == 0:
        for j, row in enumerate(mass):
            mass[j] = row[:i] + row[i+1:]

print("\n".join(mass))



