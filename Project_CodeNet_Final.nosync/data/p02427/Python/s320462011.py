n = int(input())

for d in range(2 ** n):

    d_bin = "{:b}".format(d)

    list_e = []

    for cnt, bit in enumerate(reversed(d_bin)):
        if bit == "1":
            list_e.append(cnt)

    if list_e:
        print(f"{d}: ", end="")
        print(*list_e)
    else:
        print(f"{d}:")

