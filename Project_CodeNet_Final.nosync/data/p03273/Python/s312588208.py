if __name__ == "__main__":
    H, W = map(int, input().split())
    a = list()
    for i in range(H):
        a.append(input())
    
    # 黒がある場所のリスト化
    col_list = list()
    row_list = list()

    for i in range(H):
        for j in range(W):
            if a[i][j] == '#':
                if (i in row_list) is False:
                    row_list.append(i)
                if (j in col_list) is False:
                    col_list.append(j)
    
    for i in range(H):
        ans = ''
        for j in range(W):
            if (j in col_list) and (i in row_list):
                ans += a[i][j]
        if len(ans) > 0:
            print(ans)
