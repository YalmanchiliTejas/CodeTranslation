import copy
n,m=map(int,input().split())
ab=[]
for i in range(m):
    ab.append(list(map(int,input().split())))

ans=0
def dfs(start,finish):
    global ans
   # print(finish)
    if len(finish)==n:#全部回ってたら終了
        ans+=1
    else:
        for i in adlist[start-1]:
            if i not in finish:#通ったところに入っていないなら通れるということ   
                #print(i)
                #print(adlist)
                #print(finish,1)
                finish_1 = set([i]) | finish
                #print(finish_1,2)
                dfs(i,finish_1)#finish=だと繰り返しの時に更新されるのでダメ copyもダメ　addが使えない　和集合出ないとfinishが更新されてしまう
#finishを一回ごとに変えないといけない
adlist=[]
for h in range(n):    
    adlist.append([])
for j in range(m):
    x=ab[j][0]
    y=ab[j][1]
    adlist[x-1].append(y)
    adlist[y-1].append(x)
finish=set()
finish.add(1)
#print(adlist)
dfs(1,finish)#引数がけすノード
print(ans)