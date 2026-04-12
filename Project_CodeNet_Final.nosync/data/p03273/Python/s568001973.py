import sys
sdin = sys.stdin.readline

h,w = map(int, sdin().split())
field = []
for hi in range(h):
    field.append(sdin())
    
f2 = []
for hi in range(h):
    if field[hi].count("#") > 0:
        f2.append(field[hi])
    
f2_char = [list(f2[hi]) for hi in range(len(f2))]

# 列を圧縮
has_black_list = []
for wj in range(w):
    has_black = False
    for hi in range(len(f2)):
        if f2_char[hi][wj] == "#":
            has_black = True    
    
    if has_black:
        has_black_list.append(wj)
        
field_ans = [["" for wj in range(len(has_black_list))] for hi in range(len(f2))]
for j, wj in enumerate(has_black_list):
    for hi in range(len(f2)):
        field_ans[hi][j] = f2_char[hi][wj]
    

for hi in range(len(f2)):
    print("".join(field_ans[hi]))