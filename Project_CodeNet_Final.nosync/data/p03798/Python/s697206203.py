def derive_adjacency(animal, statement, neighbor):
    if animal + statement in ['So', 'Wx']:
        return neighbor
    else:
        return 'W' if neighbor == 'S' else 'S'

input()
S = input()
for a, b in ['SS', 'SW', 'WS', 'WW']:
    tmp = derive_adjacency(a, S[0], b) + a + b
    for c in S[1:]:
        tmp += derive_adjacency(tmp[-1], c, tmp[-2])
    if tmp[:2] == tmp[-2:]:
        print(tmp[1:-1])
        break
else:
    print(-1)