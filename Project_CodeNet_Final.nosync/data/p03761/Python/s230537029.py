n = int(input())
s = list(input())
for i in range(n-1):
    tmp = []
    foo = list(input())
    for j in s:
        if j in foo:
            tmp.append(j)
            foo.remove(j)
    s = tmp
print("".join(sorted(s)))
