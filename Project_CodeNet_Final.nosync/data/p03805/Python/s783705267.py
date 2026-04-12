def main():

    n, m = map(int, input().split())
    tree = [[]*n for i in range(n)]
    l = [list(map(int, input().split())) for _ in range(m)]
    
    for i in l:
        tree[i[0]-1].append(i[1]-1)
        tree[i[1]-1].append(i[0]-1)

    ver = [i for i in range(n)]

    cnt = 0

    def dfc(now, moved):
        
        nonlocal cnt
     
        moved.sort()
        if moved == ver:
            cnt += 1

        for i in tree[now]:
            if i in moved:
                continue
            dfc(i, moved + [i])

    dfc(0, [0])
    print(cnt)
    
if __name__ == "__main__":
    main()