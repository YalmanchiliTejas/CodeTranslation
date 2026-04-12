n,x,m=map(int,input().split())
order=[-1 for i in range(m)] #-1のところにはまだ対応する余りがない、余りは高々m通り
index=0 #何番目に出た余りなのかを示す
a=[] #数列
while order[x]==-1: #ループが完成するまでは
  order[x]=index #xはindex番目の余り
  a.append(x)
  x=(x**2)%m
  index+=1
tmp=sum(a[order[x]:index]) #1ループの和、xがループの始点の余り
t=index-order[x] #1ループの長さ
if n-1<order[x]: #ループが完成しない場合
  print(sum(a[:n]))
else:
  sum1=sum(a[:order[x]]) #ループの前の和
  x1=n-order[x] #ループ部分の長さ
  n1=x1//t #ループの回数
  n2=x1%t
  print(sum1+n1*tmp+sum(a[order[x]:order[x]+n2]))