import sys
N = int(input())
s = input()
def verify(s, tmpAns):
    global N
    for i in range(N):
        if (s[i] == 'o' and tmpAns[i] == 'S') \
                or (s[i] == 'x' and tmpAns[i] == 'W'):
                    if tmpAns[(i+1)%N] != tmpAns[(i-1+N)%N]:
                        return False
        elif (s[i] == 'x' and tmpAns[i] == 'S') \
                or (s[i] == 'o' and tmpAns[i] == 'W'):
                    if tmpAns[(i+1)%N] == tmpAns[(i-1+N)%N]:
                        return False
    return True

for i in range(4):
    a = 'S' if i & 1 else 'W'
    b = 'S' if i & 2 else 'W'
    tmpAns = a + b
    for j in range(N-2):
        c = s[j+1]
        a, b = tmpAns[j], tmpAns[j+1]
        # print('a: %s, b: %s, c: %s' % (a, b, c))
        if c == 'o' and b == 'W':
            tmpAns += 'W' if a == 'S' else 'S'
        elif c == 'o' and b == 'S':
            tmpAns += 'S' if a == 'S' else 'W'
        elif c == 'x' and b == 'W':
            tmpAns += 'S' if a == 'S' else 'W'
        elif c == 'x' and b == 'S':
            tmpAns += 'W' if a == 'S' else 'S'
    # print(tmpAns)
    if verify(s, tmpAns):
        print(tmpAns)
        sys.exit(0)
print(-1)
