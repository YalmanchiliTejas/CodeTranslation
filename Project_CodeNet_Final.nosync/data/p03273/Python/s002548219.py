h, w = map(int,input().split())

squares = []
for i in range(h):
    row = list(input())
    squares.append(row)

while True:
    continue_judge = False

    for i,l in enumerate(squares): # 横を消す
        if "#" not in l:
            squares.pop(i)
            h -= 1

    for i in range(w): # 縦を消す
        delete_judge = True

        for l in squares:
            if l[i] == "#":
                delete_judge = False
                break

        if delete_judge == True:
            for l in squares:
                l.pop(i)
            w -= 1
            continue_judge = True
            break

    if continue_judge == False:
        break


for l in squares:
    for i in l:
        print(i, end = "")
    print("")