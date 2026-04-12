n = int(input())
s = ["0"] + sorted(list(input()))
for _ in range(n - 1):
    t = ["0"] + sorted(list(input()))
    u = []
    p = s.pop()
    q = t.pop()
    while True:
        if p == "0" or q == "0":
            s = ["0"] + sorted(u)
            break
        if p == q:
            u.append(p)
            p = s.pop()
            q = t.pop()
        elif p > q:
            p = s.pop()
        else:
            q = t.pop()
s.remove("0")
print("".join(s))