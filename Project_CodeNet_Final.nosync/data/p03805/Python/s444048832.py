n,m=map(int,input().split())
s=[list(map(int,input().split())) for _ in range(m)]

#各部屋の通じてる部屋番のリストを作る
l=[[] for _ in range(n)]
for i in range(m):
    a,b=s[i][0],s[i][1]
    l[a-1].append(b)
    l[b-1].append(a)

def dfs(now, prev, visited):
    visited.append(now)#行った頂点を追加していって全て行ったなら+1
    if len(visited) == n:
        return 1
 
    ret = 0 #条件を満たす数の初期値
    for edge in l[now-1]:#今の場所からいける頂点がまだ行ったことのない場合そこを同様に再度探索
        if edge == prev:
            continue
        if edge in visited:
            continue
 
        ret += dfs(edge, prev, visited[:])#そこで全ての頂点を網羅したなら+1(dfs文最初の部分)
 
    return ret #総計値を返す

print(dfs(1, 0, []))