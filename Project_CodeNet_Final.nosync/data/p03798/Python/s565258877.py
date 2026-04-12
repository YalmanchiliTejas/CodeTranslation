pattern = [('S','S'), ('S','W'), ('W', 'S'), ('W','W')]
N = int(input())
S = input()

ret = '-1'

def check(s, animal, neighbor1, neighbor2):
    if animal == 'W': s = 'x' if s == 'o' else 'o'
    return (s == 'o' and neighbor1 == neighbor2) or (s == 'x' and neighbor1 != neighbor2)

for p in pattern:
    ret_temp = p[0]+p[1]
    first, second = p[0], p[1]
    for i in range(1, N-1):
        equalty = 0 if S[i] == 'o' else 1
        if second == 'W':
            equalty = equalty^1
        if equalty == 0:
            next_animal = first
        else:
            next_animal = 'W' if first == 'S' else 'S'
        ret_temp += next_animal

        first = second
        second = next_animal
        if not check(S[i], ret_temp[i], ret_temp[i-1], ret_temp[i+1]): break
            
    if check(S[0], ret_temp[0], ret_temp[1], ret_temp[-1]) and check(S[N-1], ret_temp[N-1], ret_temp[N-2], ret_temp[0]):
        # print('ok:', ret_temp)
        ret = ret_temp
        break
    # else: print('ng:', ret_temp)

print(ret)