def mi():
    return map(int, input().split())

def ii():
    return int(input())

def main():
    X, Y, Z = mi()
    k = X//(Y+Z)
    r = X%(Y+Z)
    if r < Z:
        print(k-1)
    else:
        print(k)


if __name__ == '__main__':
    main()