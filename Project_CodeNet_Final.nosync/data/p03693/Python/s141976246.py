if __name__ == '__main__':
    r, g, b = map(int, input().split())
    num = 100 * r + 10 * g + b
    if num % 4 == 0:
        print("YES")
    else:
        print("NO")