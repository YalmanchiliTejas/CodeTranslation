def f(n, s, t):
    for i in range(2, n):
        if (t[i-2] == t[i-1] and s[i-1] == 'o') or (t[i-2] != t[i-1] and s[i-1] == 'x'):
            t += 'S'
        else:
            t += 'W'
    for i in range(0, 2):
        if (t[(i+n-2)%n] == t[(i+n-1)%n] and s[(i+n-1)%n] == 'o') or (t[(i+n-2)%n] != t[(i+n-1)%n] and s[(i+n-1)%n] == 'x'):
            if t[i] != 'S': return ":("
        else:
            if t[i] != 'W': return ":("
    return t
n = int(input())
s = input()
u = ["SS", "SW", "WS", "WW"]
for i in range(4):
    t = f(n, s, u[i])
    if t != ":(":
        print(t)
        exit(0)
print(-1)

