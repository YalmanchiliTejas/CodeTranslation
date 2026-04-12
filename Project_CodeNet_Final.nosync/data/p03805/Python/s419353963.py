n,m=map(int,input().split())

#グラフの問題は行き先を入力の段階でしまっておく
to = [[] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    to[a].append(b)
    to[b].append(a)
#grobalで答えを管理
cnt = 0
#i現在いる、visited過去行った
def search(i,visited):
    global cnt
    if len(visited)==n:
        cnt += 1
    #隣に行って、現在を過去に追加
    #forで再帰先が複数になるが、searchの値を求めるわけではなくsearchでループを回すのが目的なのでok
    #if v not in visitedを満たすものがない(行けるとこはもう行った)ならそのループは終了
    for v in to[i]:
        if v not in visited:
            search(v,visited+[v])
search(0,[0])
print(cnt)