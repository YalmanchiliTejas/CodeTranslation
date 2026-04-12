def inductive_inference(animal, statement, other):
    if animal == 'S':
        if statement == 'o':
            return other
        else:
            return {'S': 'W', 'W': 'S'}[other]
    else:
        if statement == 'x':
            return other
        else:
            return {'S': 'W', 'W': 'S'}[other]

N = int(input())
S = input()
for a1, a2 in ['SS', 'SW', 'WS', 'WW']:
    assumption = inductive_inference(a1, S[0], a2)  # the animal numbered N
    a, b = a1, a2
    animals = [assumption, a, b]
    for c in S[1:]:
        a, b = b, inductive_inference(b, c, a)
        animals.append(b)
    if animals[1] == animals[-1] and animals[0] == animals[N]:
        print(''.join(animals[1:-1]))
        exit()
print(-1)