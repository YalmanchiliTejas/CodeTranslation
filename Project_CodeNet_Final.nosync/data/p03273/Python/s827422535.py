def main():
    H, W = map(int, input().split())

    A = [list(input()) for i in range(H)]

    B = []
    for a in A:
        if a.count('#') != 0:
            B.append(a)
    
    B = list(map(list, zip(*B)))
    C = []
    for b in B:
        if b.count('#') != 0:
            C.append(b)

    C = list(map(list, zip(*C)))

    for c in C:
        print(*c, sep='')



main()