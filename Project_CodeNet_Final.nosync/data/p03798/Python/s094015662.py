n=int(input())
s=input()

#末尾と1番目を羊または狼と仮定して貪欲。4パターン
import itertools
for x,y in itertools.product(["S","W"], repeat=2):
  ans=[None]*n
  ans[-1]=x
  ans[0]=y
  flag=1
  for i in range(n): #各発言から次の動物を特定する。末尾らへんにきたら矛盾を検証
    if 0<=i<=n-3: #このifに関して間違ってないはず…
      if ans[i]=="S":
        if s[i]=="o":
          ans[i+1]=ans[i-1] #同じと言ってる場合は同じのため、次の番号は2つ前と同じ動物。
        else: #そうじゃない場合は、次の番号は2つ前と違う動物。
          if ans[i-1]=="W":
            ans[i+1]="S"
          else:
            ans[i+1]="W"
      #今の番号が狼の場合は上の全部逆にする
      if ans[i]=="W": 
        if s[i]=="x":
          ans[i+1]=ans[i-1]
        else:
          if ans[i-1]=="W":
            ans[i+1]="S" 
          else:
            ans[i+1]="W"
    else: #iがn-2とn-1の場合は、先頭と末尾の羊を指定するため、矛盾を確認しないといけない。こっからが肝だよ
      if ans[i]=="S":
        if s[i]=="o":
          if ans[(i+1)%n]!=ans[i-1]:
            flag=0
        else:
          if ans[(i+1)%n]==ans[i-1]:
            flag=0
      #今の番号が狼の場合は上の全部逆にする
      if ans[i]=="W":
        if s[i]=="x":
          if ans[(i+1)%n]!=ans[i-1]:
            flag=0
        else:
          if ans[(i+1)%n]==ans[i-1]:
            flag=0
  if flag==1:
    print("".join(ans))
    exit()

#どんなケースでも矛盾するとループを抜けてしまう
print(-1)