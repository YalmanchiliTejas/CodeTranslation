h,w = map(int,input().split())
src = [input() for _ in range(h)]
li = []
for i,z in enumerate(src[0]):
    if z == '.':
        li.append(i)
eliminate_column_index = []
for l in li:
    tmp = True
    for s in src:
        if s[l] == '#':
            tmp = False
            break
    if tmp == True:
        eliminate_column_index.append(l)
eliminate_row_index = []
for si,sr in enumerate(src):
    if sr == '.'*w:
        eliminate_row_index.append(si)
for s_row,ss in enumerate(src):
    if s_row in eliminate_row_index:
        continue
    tmp = ''
    for i,s in enumerate(ss):
        if i not in eliminate_column_index:
            tmp += s
    if tmp != '':
        print(tmp)