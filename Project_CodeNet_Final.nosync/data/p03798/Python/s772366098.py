N = int(input())
s = input().strip()


def check(a, b):
    v = [0]*N
    v[0] = a
    v[1] = b
    for i in range(1, N-1):
        if s[i] == 'o':
            if v[i]:
                v[i+1] = v[i-1]
            else:
                v[i+1] = not v[i-1]
        else:
            if v[i]:
                v[i+1] = not v[i-1]
            else:
                v[i+1] = v[i-1]

    ok = True
    for i in range(N):
        same = v[(i-1) % N] == v[(i+1) % N]
        if s[i] == 'o':
            if v[i] != same:
                ok = False
        else:
            if v[i] == same:
                ok = False

    return v if ok else None


p = [
    [True, True],
    [False, False],
    [True, False],
    [False, True]
]
ans = "-1"
for a, b in p:
    l = check(a, b)
    if l != None:
        ans = "".join(["S" if v else "W" for v in l])
        break
print(ans)
