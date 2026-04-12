H, W = map(int, input().split())

MAP = [list(input()) for i in range(H)]
check = ['.' for j in range(W)]
MAP_h = []
MAP_T = []

for i in range(H):
    if check != MAP[i]:
        MAP_h.append(MAP[i])
   
check = ['.' for k in range(len(MAP_h))]   

for i in range(W):
    tmp = [row[i] for row in MAP_h]
    if tmp != check:
        MAP_T.append(tmp)

MAP= map(list, zip(*MAP_T))

for l in MAP:
    print(''.join(l))
