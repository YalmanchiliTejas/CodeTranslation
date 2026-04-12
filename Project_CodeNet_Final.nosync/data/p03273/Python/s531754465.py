h,w = map(int,input().split())
data_t = []
for _ in range(h):
    list_ = str(input())
    data_t.append(list_)

data = []
for i in range(h):
    data.append([])
    for  j in range(w):
        data[i].append(data_t[i][j])
    
for i in range(h):
    contw=True
    line = ""
    for j in range(w):
        c = data[i][j]
        if c == "#":
            contw = False
            line+="#"
        elif c == ".":
            pre = True
            for k in range(h):
                if data[k][j] == "#":
                    pre = False
            if pre == True:
                for k in range(h):
                    data[k][j] = "_"
            else:
                line+="."
    if contw == False:
        print(line)