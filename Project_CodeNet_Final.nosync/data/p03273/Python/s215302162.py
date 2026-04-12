
def main():

    H, W = map(int, input().split())

    mat = []
    for _ in range(H):
        A = input()

        flag = False
        for a in A:
            if a != '.':
                flag = True
        if flag:
            mat.append(A)

    l = []
    for i in range(W):
        flag = True
        for ary in mat:
            if ary[i] != '.':
                flag = False
                break
        if not flag:
            l.append(i)

    for s in mat:
        for i in l:
            print(s[i], end="")
        print()

main()