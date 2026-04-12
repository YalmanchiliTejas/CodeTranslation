h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
loop_flag = True
while loop_flag:
    loop_flag = False

    for i in range(h):
        f = True
        for j in range(w):
            if a[i][j] != ".":
                f = False
                break
                print(i, "breaked")
        if f:
            loop_flag = True
            a.pop(i)
            h -= 1
            break
            
    #print(a, h, w)

    for j in range(w):
        f = True 
        for i in range(h):
            # print(i, j, a[i][j])
            if a[i][j] != ".":
                f = False
                break
        if f:
            loop_flag = True
            for i in range(h):
                a[i].pop(j)
            w -= 1
            break
        
for i in range(h):
    print("".join(a[i]))

