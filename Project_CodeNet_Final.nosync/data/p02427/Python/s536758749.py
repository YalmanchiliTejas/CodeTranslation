n = int(input())
for i in range(2**n):
    if i == 0:
        print("0:")
        continue
    else:
        print("{}: ".format(i), end="")
    l = []
    for j in range(n):
        if i & (1 << j) != 0:
            l.append(j)
    print(*l)
