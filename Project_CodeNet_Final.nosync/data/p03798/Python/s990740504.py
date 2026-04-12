import sys

def SorW(i):
    if i == 0:
        j = N - 1
    else:
        j = i - 1
    if t[i] == 'S' and t[j] == 'S':
        if s[i] == 'o':
            a = 'S'
        else:
            a = 'W'
    elif t[i] == 'S' and t[j] == 'W':
        if s[i] == 'o':
            a = 'W'
        else:
            a = 'S'
    elif t[i] == 'W' and t[j] == 'W':
        if s[i] == 'o':
            a = 'S'
        else:
            a = 'W'
    else:
        if s[i] == 'o':
            a = 'W'
        else:
            a = 'S'
    return a

N = int(input())
s = str(input())

for t in [['S', 'S'], ['S', 'W'], ['W', 'W'], ['W', 'S']]:
    for i in range(1, N):
        t.append(SorW(i))
    if t[0] == t[N] and t[1] == SorW(0):
        del t[N]
        print(''.join(t))
        sys.exit()
print('-1')
