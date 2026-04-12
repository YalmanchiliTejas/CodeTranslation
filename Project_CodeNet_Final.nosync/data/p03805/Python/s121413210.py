def main():
    n, m = map(int, input().split())
    mat = [[0]*n for i in range(n)]
    l = [list(map(int, input().split())) for _ in range(m)]
 
    for i in l:
        mat[i[0]-1][i[1]-1] = 1
        mat[i[1]-1][i[0]-1] = 1
 
    
    ver = [i for i in range(n)]
 
    cnt = 0
 
    def dfc(now, moved):
        
        nonlocal cnt
 
        moved.sort()
        if moved == ver:
            cnt += 1
        
        for i in range(n):
            if (mat[now][i] == 0) or (i in moved):
                continue
            
            dfc(i, moved + [i])
 
    dfc(0, [0])
    print(cnt)
    
if __name__ == "__main__":
    main()