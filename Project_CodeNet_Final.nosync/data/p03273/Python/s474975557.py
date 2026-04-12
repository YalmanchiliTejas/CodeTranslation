# coding: utf-8

(row_count, col_count) = [int(i) for i in input().rstrip().split(" ")]

def shrink_col(map):
    new_map = [[] for i in range(len(map))]
    for i in range(col_count):
        all_space = True
        for j in range(len(map)):
            if map[j][i] == '#':
                all_space = False
                break
        if not all_space:
            for j in range(len(map)):
                new_map[j].append(map[j][i])
    return new_map

def shrink_row(map):
    new_map = []
    for i in range(row_count):
        if len([j for j in map[i] if j == "#"]) > 0:
            new_map.append(map[i])
    return new_map


map = [input().rstrip() for i in range(row_count)]
map = shrink_row(map)
map = shrink_col(map)

for row in map:
    print("".join(row))
