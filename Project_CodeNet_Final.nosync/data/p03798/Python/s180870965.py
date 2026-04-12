n = int(input())
s = input()

ans = '-1'
# 4 pattern of last-first animals
for animals in ['SS', 'SW', 'WS', 'WW']:
    for say in s:
        if (animals[-1] == 'S') != ((say == 'o') != (animals[-2] == 'S')):
            animals += 'S'
        else:
            animals += 'W'
    if animals[:2] == animals[-2:]:
        ans = animals[1:-1]

print(ans)