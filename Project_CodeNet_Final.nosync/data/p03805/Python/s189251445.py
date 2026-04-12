N,M=map(int,input().split(' '))
A=[sorted(list(map(int,input().split(' ')))) for i in range(M)]
ans=0
stack=[1]
visited=[1]
def dfs():
    global stack
    global ans
    #終了判定
    if stack==[]:
        return None
    else:
        #これ以上訪問できるnodeがないとき
        if len(stack)==N: #全訪問した
            ans+=1
            stack.pop(0)
        else:
            for i in range(1,N+1): #未訪問の子ノードを検討
                if i not in stack and sorted([stack[0], i]) in A:
                    stack = [i] + stack
                    dfs()
            stack.pop(0)
dfs()
print(ans)