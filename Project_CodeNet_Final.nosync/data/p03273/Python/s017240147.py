def mi():
    return map(int, input().split())

def ii():
    return int(input())

def cut(a):
    w = len(a[0])
    l = []
    for row in a:
        if row != ['.']*w:
            l.append(row)
    return l

def main():
    H, W = mi()
    a = [list(input()) for _ in range(H)]
    a = cut(a)
    a = cut([list(i) for i in zip(*a)])
    [print(''.join(list(i))) for i in zip(*a)]

if __name__ == '__main__':
    main()