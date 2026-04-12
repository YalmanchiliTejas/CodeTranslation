def main():
    input()
    *H, = map(int, input().split())

    cnt = 0
    height = 0
    for h in H:
        if height <= h:
            cnt += 1
            height = h
    print(cnt)


main()
