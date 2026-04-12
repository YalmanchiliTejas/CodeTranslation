n,x,m=map(int,input().split())
a=[x]
check=set()
check.add(x)

past=x
cnt=1
while(1):
  now=(past**2)%m
  if now not in check:
    a.append(now)
    check.add(now)
    cnt+=1
    past=now
    if cnt==n:
      print(sum(a))
      exit()
  else:
    #timeは周期の長さ
    time=len(a)-a.index(now)
    #timeより前のものをpreとする
    pre=a.index(now)
    #preの合計
    pre_sum=sum(a[:a.index(now)])
    #循環したものの合計
    time_sum=((n-pre)//time)*sum(a[a.index(now):len(a)])+sum(a[a.index(now):a.index(now)+(n-pre)%time])
    
    print(pre_sum+time_sum)
    exit()
  
  
  