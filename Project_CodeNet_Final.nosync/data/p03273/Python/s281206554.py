"""
B - Grid Compression
ex in )
4 4
##.#
....
##.#
.#.#

ex out)
###
###
.##
"""

H, W = map(int, input().split())

matrix = []
for h in range(H):
    line = list(input())
    
    line_num = []
    for part in line:
        line_num.append(part)
    
    matrix.append(line_num)

leave_h = []
for h in range(H):
    for w in range(W):
        # 黒ならのこす
        if matrix[h][w] == "#":
            leave_h.append(h)
            break

leave_w = []
for w in range(W):
    for h in range(len(matrix)):
        
        # 黒ならのこす
        if matrix[h][w] == "#":
            leave_w.append(w)
            break


for h in range(H):
    if h not in leave_h:
        continue

    for w in range(W):
        if w not in leave_w:
            continue

        print(matrix[h][w], end="")
    
    print()
