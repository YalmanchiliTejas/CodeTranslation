def main():
    h,w=map(int,input().split())
    a = [list(input()) for _ in range(h)]
    b = []
    for i in a:
        if i.count(".") != w:
            b.append(i)
    for i in list(range(w))[::-1]:
        for j in b:
            if j[i] == "#":
                break
        else:
            for j in range(len(b)):
                del b[j][i]
    for x in b:
        print("".join(x))

if __name__ == "__main__":
    main()