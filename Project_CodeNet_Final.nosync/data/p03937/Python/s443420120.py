h,w = map(int,input().split())
left = 0
ok = True
flag = "ok"
for i in range(h):
    dum = input()
    for j in range(0,w):
        if j < left and dum[j] == "#":
            print("Impossible")
            exit()
        if dum[j] == "#":
            left_o = j
            flag = "ng"
    left = left_o
    flag = "ok"
print("Possible")