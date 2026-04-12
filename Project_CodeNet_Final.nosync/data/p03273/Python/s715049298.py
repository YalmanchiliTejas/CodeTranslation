def main():
    h, w = map(int, input().split())
    a = []
    for i in range(h):
        a.append(list(input()))

    c_h = []
    c_w = []

    for i in range(h):
        flag = False
        for j in range(w):
            if a[i][j] == '#':
                flag = True
                break
        
        if flag:
            c_h.append(i)

    for i in range(w):
        flag = False
        for j in range(h):
            if a[j][i] == '#':
                flag = True
                break
        if flag:
            c_w.append(i)

    new_a = []

    if len(c_h) == 0:
        if not len(c_w) == 0:

            for i in range(h):
                temp = []
                for j in c_w:
                    temp.append(a[i][j])
                new_a.append(temp)

    elif len(c_w) == 0:
        if not lne(c_h) == 0:

            for i in range(w):
                temp = []
                for j in c_h:
                    temp.append(a[j][i])
                new_a.append(temp)

    elif not(len(c_h) == 0 or len(c_w) == 0):
        for i in c_h:
                temp = []
                for j in c_w:
                    temp.append(a[i][j])
                new_a.append(temp)
    
    else:
        pritn()
        return 0


    for i in new_a:
        print(''.join(i))
    

if __name__ == '__main__':
    main()