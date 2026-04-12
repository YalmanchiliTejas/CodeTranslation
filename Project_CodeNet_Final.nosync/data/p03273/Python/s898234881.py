h, w = map(int, input().split())
color = []
count = 0
for i in range(h):
    tmp = input()
    if "#" in tmp:
        count +=1
        color.append(tmp)

column_count = [0] * w
for i in range(count):
    for j in range(w):
        if color[i][j] ==".":
            column_count[j]+=1

show_index = [i for i in range(len(column_count)) if column_count[i]<count]            
for i in range(count):
    content = ""
    for j in show_index:
        content += color[i][j]
    print(content)