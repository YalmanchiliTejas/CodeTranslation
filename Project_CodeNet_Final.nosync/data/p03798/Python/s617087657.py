# -*- coding: utf-8 -*-

N = int(input())
statements = list(str(input()))
patterns = [['S', 'S'], ['S', 'W'], ['W', 'S'], ['W', 'W']]
null_flg = 1

for pattern in patterns:
    animals = pattern
    for index in range(1, N-1):
        rule = statements[index] + animals[index]
        if rule == 'oS':
            animals.append(animals[index - 1])
        elif rule == 'xS':
            if animals[index - 1] == 'S':
                animals.append('W')
            else:
                animals.append('S')
        elif rule == 'oW':
            if animals[index - 1] == 'S':
                animals.append('W')
            else:
                animals.append('S')
        elif rule == 'xW':
            animals.append(animals[index - 1])

    last_flg = first_flg = 0
    last = statements[-1] + animals[-1]
    if last == 'oS':
        if animals[0] == animals[-2]:
            last_flg = 1
    elif last == 'xS':
        if animals[0] != animals[-2]:
            last_flg = 1
    elif last == 'oW':
        if animals[0] != animals[-2]:
            last_flg = 1
    elif last == 'xW':
        if animals[0] == animals[-2]:
            last_flg = 1

    if last_flg:
        first = statements[0] + animals[0]
        if first == 'oS':
            if animals[-1] == animals[1]:
                print(''.join(animals))
                null_flg = 0
                break
        elif first == 'xS':
            if animals[-1] != animals[1]:
                print(''.join(animals))
                null_flg = 0
                break
        elif first == 'oW':
            if animals[-1] != animals[1]:
                print(''.join(animals))
                null_flg = 0
                break
        elif first == 'xW':
            if animals[-1] == animals[1]:
                print(''.join(animals))
                null_flg = 0
                break

if null_flg:
    print('-1')