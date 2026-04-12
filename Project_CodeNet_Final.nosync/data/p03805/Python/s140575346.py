#始点1から全ノードを通る経路の総数
#解答：
#基本DFSだが、ゴールしたらゴールの訪問予定フラグを消す
#ゴールしたら分岐点からまたDFS


N,M=map(int,input().split())
#dc={}
lc=[[] for _ in range(N)]#インデは-1、要素はそのまま
for i in range(M):
    a,b=map(int,input().split())
    #if not a in
    lc[a-1].append(b)
    lc[b-1].append(a)
#st=[1]
#print(lc)
st=[[1,0]]
#df={1:1}
df={}
lp=[0]
ans=0
while st:
    #tmp=st.pop()
    tmptp=st.pop()
    #print("tmptp",tmptp)
    tmp=tmptp[0]
    ptmp=tmptp[1]
    p=lp.pop()
    while p!=ptmp:
        del df[p]
        p=lp.pop()
    lp.append(p)
    lp.append(tmp)
    df[tmp]=1
    if len(df)==N:
        ans+=1
        #del df[tmp]
        #print("lp",lp)
        #print("df",df)
    for c in lc[tmp-1]:
        if not c in df:
            #st.append(c)
            st.append([c,tmp])
            #df[c]=1
print(ans)
