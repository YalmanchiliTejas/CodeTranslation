a,b,c,x,y=map(int,input().split())
ans=1000000000
for i in range (0,(max(x,y)*2+1),2):#abピザを何枚買ったか考える。偶数枚しかありえないことに注意
  price=c*i+a*(max(0,(x-int(i/2))))+b*(max(0,(y-int(i/2))))
  ans =min(price,ans)
  #abピザの枚数が決まると残りは単品による購入となるので、
  #自動的に購入枚数は決定する。O(n)全探索で済むので間に合う。
  
print(ans)