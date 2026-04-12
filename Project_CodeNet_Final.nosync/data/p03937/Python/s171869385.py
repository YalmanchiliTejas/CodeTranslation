def main():
    h, w = map(int,input().split())
    a = [list(input()) for _ in range(h)]
    cnt=0
    for i in range(h):
        for j in range(w):
            if a[i][j] == '#':
                cnt += 1
    if cnt == h+w-1:
        print('Possible')
    else:
        print('Impossible')

if __name__ == '__main__':
    main()
