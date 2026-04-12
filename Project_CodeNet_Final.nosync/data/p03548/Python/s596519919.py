def main():
    x, y, z = map(int, input().split())
    x -= 2*z

    i, cnt = 0, 0
    while (1):
        if i%2 == 0:
            x -= y
            if x < 0:
                break
            cnt += 1
        else:
            x -= z
            if x < 0:
                break
        i += 1
    print(cnt)


if __name__ == '__main__':
    main()