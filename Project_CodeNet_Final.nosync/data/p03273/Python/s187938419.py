h,w = map(int,input().split())
map_ = list()
for i in range(h):
    map_.append(list(input()))
flag = True
while flag:

    flag = False

    for ii in range(len(map_)):
        if set(map_[ii]) == {"."}:
            del map_[ii]
            flag = True
            break

    map_t = [list(x) for x in zip(*map_)]

    for ii in range(len(map_t)):
        if set(map_t[ii]) == {"."}:
            del map_t[ii]
            flag = True
            map_ = [list(x) for x in zip(*map_t)]
            break

    map_ = [list(x) for x in zip(*map_t)]

for iiii in map_:
    print(*iiii,sep="")