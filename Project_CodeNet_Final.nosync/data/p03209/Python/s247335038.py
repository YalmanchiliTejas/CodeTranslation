n,x = map(int, input().split())

tmp = 1
pat = 1
plist = [1]
bag_list = [1]
for i in range(n):
    tmp = 1 + tmp + 1 + tmp + 1
    pat = pat * 2 + 1
    bag_list.append(tmp)
    plist.append(pat)

def calc(x, nn):
    if x == 1:
        return 1 if nn == 0 else 0
    tt = bag_list[nn-1] + 2
    # print(nn,x,tt)
    if x == tt:
        # print(plist[nn-1] + 1)
        return plist[nn-1] + 1
    elif x == bag_list[nn]:
        # print(plist[nn])
        return plist[nn]
    elif x < tt:
        # print(0)
        return calc(x-1, nn-1)
    elif x > tt:
        # print(plist[nn-1] + 1)
        return calc(x-1-1-bag_list[nn-1], nn-1) + plist[nn-1] + 1

print(calc(x, n))
