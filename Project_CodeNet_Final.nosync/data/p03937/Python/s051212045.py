M = []
ans = []

def main():
    H,W = map(int, input().split())  
    for i in range(H):
        M.append(input())
        ans.append('.' * W)

    bfs(0,0)

    for i in range(H):
        if(M[i] != ans[i]):
            print('Impossible')
            return
    print('Possible')


def bfs(x,y):
    if(x>=len(M) or y>=len(M[0])):
        return False
    if(M[x][y]=='#'):
        str_list = list(ans[x])
        str_list[y] = '#'
        ans[x] = "".join(str_list) 
        if(bfs(x,y+1) & bfs(x+1,y)):
            #失敗にする、気持ち悪いけど楽…
            str_list = list(ans[0])
            str_list[0] = '.'
            ans[0] = "".join(str_list) 
        return True
    return False


if __name__ == '__main__':
    main()

