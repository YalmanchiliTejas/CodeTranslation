H, W = map(int, input().split())

a = []

for _ in range(H):
    a.append(input())

# horizon
h_remove_index = []
for h_i in range(H):
    if not "#" in a[h_i]:
        h_remove_index.append(h_i)




#vertex
v_remove_index = []
for v_i in range(W):
    is_ok = True
    for h_i in range(len(a)):
        if a[h_i][v_i] == "#":
            is_ok = False
            break
    # remove
    if is_ok:
        v_remove_index.append(v_i)
    

for h_i in range(H):
    if h_i in h_remove_index:
        continue
    for v_i in range(W):
        if v_i in v_remove_index:
            continue

        print(a[h_i][v_i], end='')
    print("\n",end='')

