n,m=map(int,input().split())
li=[tuple(map(int,input().split())) for i in range(m)]


#まず各頂点ごとに、どの頂点とつながってるかのリスト作る？
cho=[]
for i in range(n):
  temp=[]
  for x,y in li:
    if x==i+1:
      temp.append(y)
    if y==i+1:
      temp.append(x)
  cho.append(temp)
#cho[0]は、頂点1がどの頂点とつながってるかを記録してる


ans=0

#全ての頂点を訪問するまで深堀り続けるコードを書く。
#全てを訪問する前に、訪問済み頂点に来てしまったらbreak。
zumi=[1]
queue=[[cho[0],0,len(cho[0])]]
dankai=0

#print(queue)
while 1:
  #print("今は",dankai,"段目のを調べてます")
  if queue[dankai][1]<queue[dankai][2]:
    bango=queue[dankai][0][queue[dankai][1]]
    if bango not in zumi: #それが訪問済みの点でなければ、次にその頂点のchoを調べよう。
      dankai+=1
      #print("訪問済みじゃないので次の段を調べます")
      zumi.append(bango) #それを訪問済みにする。
      queue.append([cho[bango-1],0,len(cho[bango-1])])
      #「その頂点番号につながってる頂点」「その段階において、何番目を現在調査中か」「その段階の長さ」
      if dankai==n-1:
        ans+=1 #全部の頂点を調べ終わったら、答えが増えたということのため、+1する。
    else: #それが訪問済みの点であれば、同じ段階の次の点を訪問しよう
      #print("これは訪問済みなので同じ",dankai,"段目の次の頂点を調べます")
      queue[dankai][1]+=1
  else:
    #print("どうやらこの段目にはもう頂点がないので、ひとつ前の段に戻り、その段の次の頂点に移ります")
    dankai-=1
    if dankai<0:
      break
    #その段目の番号について、訪問済み
    zumi.pop()
    queue.pop()
    queue[dankai][1]+=1
    #そうやっていって、cho[0]の点を全て調べ終わってしまったら、末尾を削除し、上の段階に戻る。
print(ans)