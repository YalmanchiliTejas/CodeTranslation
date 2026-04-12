h, w = list(map(int, input().split()))
table = [str(input()) for _ in range(h)]

# for r in table:
#     print(r)

# row
for i in range(h):
    # print(h-i)
    row = table[h-1-i]
    row = list(set(row))
    if row == ["."]:
        table.pop(h-1-i)

# print("=========")
# for r in table:
#     print(r)

# col
l = []
for j in range(w):
    # print("==")
    # print(w-j)
    col = [r[w-1-j] for r in table]
    # print(col)
    col = list(set(col))
    if col == ["."]:
        # print("YY")
        l.append(w-1-j)
        # for i in range(h):
        #     table[i] = table[i].pop(w-1-j)


# print("=========")
# for r in table:
#     print(r)

out = []
for r in table:
    ll = list(r)
    for ind in l:
        ll.pop(ind)

    out.append("".join(ll))


# print("=========")
for r in out:
    print(r)
