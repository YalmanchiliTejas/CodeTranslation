import itertools
h, w = [int(i) for i in input().split()]
a = [input() for i in range(h)]

for way in itertools.combinations([i for i in range(h + w - 2)], h - 1):
    k = 0
    l = 0
    ij_list =[[k, l]]
    #print(way)
    for i in range(h + w - 1):
        k += (i in way)
        l += (i not in way)
        ij_list.append([k, l])

    for i, j in itertools.product(range(h), range(w)):
            if [i, j] not in ij_list:
                if a[i][j] != ".":
                    break
            else:
                if a[i][j] != "#":
                    break
    else:
        print("Possible")
        break

else:
    print("Impossible")