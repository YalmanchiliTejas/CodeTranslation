a,b,c,x,y=list(map(int,input().split()))

#abピザをab枚使う
ans=float("INF")
for ab in range(0,2*max(x,y)+1,2):
  #使うお金
  #ABピザ
  cnt=ab*c
  #Aピザ
  cnt+=a*max(0,x-ab//2)
  #Bピザ
  cnt+=b*max(0,y-ab//2)
  ans=min(cnt,ans)

print(ans)

  
  