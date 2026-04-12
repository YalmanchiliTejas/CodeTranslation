def main():
    h, w = map(int, input().split())
    ary = [list(input()) for _ in range(h)]
    for i in reversed(range(h)):
        if len(ary[i]) == ary[i].count('.'):
            del ary[i]
    for i in reversed(range(w)):
        ok = True
        for a in ary:
            if a[i] != '.':
                ok = False
        if ok:
            for j in range(len(ary)):
                del ary[j][i]
    for a in ary:
        print("".join(a))


if __name__ == '__main__':
    main()
