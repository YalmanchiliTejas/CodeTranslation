h,w = map(int,input().split())
#n = int(input())
L = []
for i in range(h):
    tmp = list(input())
    if tmp != ["."]*len(tmp):
        L.append(tmp)
    else:
        h -= 1

l_2d_t = [list(x) for x in zip(*L)]

new_L = []
for i in l_2d_t:
    if i != ["."]*len(i):
        new_L.append(i)

l_2d_t = [list(x) for x in zip(*new_L)]

for i in l_2d_t:
    print("".join(i))