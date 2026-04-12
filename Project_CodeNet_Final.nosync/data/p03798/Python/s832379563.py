n = int(input())
s = input()

def search(t0, t1):
    t = [t0, t1]
    for i in range(1, n+1):
        if t[i] == 'S':
            if s[i % n] == 'o':
                t.append(t[i-1])
            else:
                if t[i-1] == 'S':
                    t.append('W')
                else:
                    t.append('S')
        else:
            if s[i % n] == 'o':
                if t[i-1] == 'S':
                    t.append('W')
                else:
                    t.append('S')
            else:
                t.append(t[i-1])

    if t[0] == t[-2] and t[1] == t[-1]:
        return t[:-2]
    else:
        return None

flg = True
for i, j in [('W', 'W'), ('S', 'S'), ('S', 'W'), ('W', 'S')]:
    if not search(i, j) is None:
        ans = search(i, j)
        print(*ans, sep='')
        flg = False
        break

if flg:
    print(-1)