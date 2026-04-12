if __name__ == '__main__':
    r, g, b = list(input().split())

    target = int(r + g + b)

    # print(target)

    if target % 4 == 0:
        print("YES")
    else:
        print("NO")
