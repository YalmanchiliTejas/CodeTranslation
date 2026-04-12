l = ['q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b']
while 1:
    a = 0
    s = raw_input()
    if s == "#":
        break;
    b = -1
    for c in s:
        if b == -1:
            b = c in l
            continue
        a += b != (c in l)
        b = c in l
    print a