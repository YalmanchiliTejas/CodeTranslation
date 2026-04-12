N = input()
str_animal = raw_input()
mat = list(str_animal)
pat = (('S', 'S'), ('S', 'W'), ('W', 'S'), ('W', 'W'))

def judge(listSW, listox):
    matSW = listSW[-2:] + listSW[:2]
    matox = listox[-2:] + listox[:2]
    for i in xrange(1,3):
        if matSW[i] == 'S':
            if matox[i] == 'o' and matSW[i-1] != matSW[i+1]: break
            if matox[i] == 'x' and matSW[i-1] == matSW[i+1]: break
        else:
            if matox[i] == 'o' and matSW[i-1] == matSW[i+1]: break
            if matox[i] == 'x' and matSW[i-1] != matSW[i+1]: break
    else:
        return 0
    return -1

for i in pat:
    animal = list(i)
    for j in xrange(1, N-1):
        if animal[j] == 'S':
            if mat[j] == 'o':
                animal.append(animal[j-1])
            else:
                if animal[j-1] == 'S':
                    animal.append('W')
                else:
                    animal.append('S')
        else:
            if mat[j] == 'o':
                if animal[j-1] == 'S':
                    animal.append('W')
                else:
                    animal.append('S')
            else:
                animal.append(animal[j-1])
    foo = judge(animal, mat)
    if foo == 0:
        print ''.join(animal)
        break
else:
    print -1