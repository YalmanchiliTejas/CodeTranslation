n = int(input())
s = sorted([input() for x in range(n)], key=lambda x: len(x))
head = s[0]
tail = list(map(list, s[1:]))
result = []
for h in head:
    for t in tail:
        if h not in t:
            break
    else:
        result.append(h)
        for t in tail:
            t.remove(h)
print("".join(sorted(result)))
