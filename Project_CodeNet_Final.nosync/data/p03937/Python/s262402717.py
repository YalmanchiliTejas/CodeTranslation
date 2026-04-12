H, W = map(int, input().split())
A = [[a for a in input()] for _ in range(H)]

ans = True
h = 0
w = 0
B = [[1 if a == '#' else 0 for a in a_list] for a_list in A]
while (ans) and not (h == H - 1 and w == W - 1):
    B[h][w] = 0
    if h == H - 1:
        if A[h][w + 1] == '.':
            ans = False
        else:
            w += 1
    elif w == W - 1:
        if A[h + 1][w] == '.':
            ans = False
        else:
            h += 1
    else:
        sh = A[h + 1][w]
        sw = A[h][w + 1]
        if sh == '#' and sw == '#':
            ans = False
        elif sh == '.' and sw == '.':
            ans = False
        elif sh == '#' and sw == '.':
            h += 1
        else:
            w += 1

s = sum([sum(b_list) for b_list in B])
if ans and s == 1:
    print("Possible")
else:
    print("Impossible")
