H,W = [int(x) for x in input().split()]
A = [list(input()) for _ in range(H)]
#%%
def dfs(h,w):
    if(A[h][w]=='.'):
        return False
    else:
        A[h][w]='.'
        x = False
        if(w<W-1):
            x = dfs(h,w+1)
        if(not x and h<H-1):
            dfs(h+1,w)
        return True

dfs(0,0)
for a in A:
    if('#' in a):
        print('Impossible')
        break
else:
    print('Possible')
