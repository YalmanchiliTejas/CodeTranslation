n = int(input())
s = input()

def check(ox, l, m, r):
    if l == r:
        if (m == 'S' and ox == 'o') or (m == 'W' and ox == 'x'):
            return True
        else:
            return False
    else:
        return not check(ox, l, m, l)

for one in 'SW':
    for two in 'SW':
        a = one + two
        for i in range(2, n):
            if check(s[i-1], a[i-2], a[i-1], 'S'):
                a += 'S'
            else:
                a += 'W'
        if check(s[n-1], a[n-2], a[n-1], a[0]) and check(s[0], a[n-1], a[0], a[1]):
            print(a)
            exit()
print(-1)