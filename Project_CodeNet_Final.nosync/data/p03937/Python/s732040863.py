h,w = map(int,input().split())
r = 0
for i in range(h):
    s = input()
    a = 0
    for j in range(w):
        if s[j] == "#":
            if j < r:
                print("Impossible")
                exit()
            else:
                a = j
        else:
            continue
    r = a

print("Possible")
