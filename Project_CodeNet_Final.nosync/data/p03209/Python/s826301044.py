n, k = [ int(v) for v in input().split() ]
burgur = [ (0,0,0,1) ]
for _ in range(51):
    x, y, z, w = burgur[-1]
    y = w + 1
    z = 2 * w + 2
    w = 2 * w + 3
    burgur.append((x,y,z,w))

def eat(level,position):
    left, middle, right, _length = burgur[level]
    if level == 0:
        return 1
    else:
        if position == left:
            return 0
        elif position == middle:
            return 2**level
        elif position == right:
            return 2**(level+1) - 1
        elif left< position < middle:
            return eat(level-1, position-1)
        elif middle< position < right:
            return 2**level + eat(level-1, position-middle-1)

print(eat(n,k-1))