h,w=map(int,input().split())
l=[list(input()) for i in range(h)]
#h+w回確認する
import numpy as np
change_h=0
change_w=w
ans=[]
for i in range(h):
    if l[i].count('.')!=w:
        ans+=[l[i][:]]
        change_h+=1
l_count=[]
for i in range(w):
    count=0
    for j in range(h):
        if l[j][i]=='.':
            count+=1
    
    if count==h:
        l_count+=[i]
    
l_count=sorted(l_count,reverse=True)#削除したい列番号を後ろから削除する
for i in l_count:
    ans=np.delete(ans,i,axis=1)
    #np.delete(a,b,c):a:配列,b:削除したい行・列番号,c:列か行か

#最後の出力
for i in range(change_h):
    print(*ans[i],sep='')