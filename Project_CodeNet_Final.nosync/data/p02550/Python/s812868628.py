def resolve():
    #n=int(input())
    #a,b=map(int,input().split())
    #x=list(map(int,input().split()))
    #a=[list(map(lambda x:int(x)%2,input().split())) for _ in range(h)]
    n,x,m=map(int,input().split())
    l=[]
    ans=0
    cnt=0
    while (x not in l)and(cnt<=n):
      l.append(x)
      ans+=x
      cnt+=1
      x=(x**2)%m
    for i in range(len(l)):
      if x==l[i]:
        break
    lc=l[i:].copy()
    lc_cnt=(n-cnt)//len(lc)
    ans+=lc_cnt*sum(lc)+sum(lc[:(n-cnt)-lc_cnt*len(lc)])
    print(ans)

if __name__ == '__main__':
    resolve()