while True:
  n=int(input()) #審判の数
  if n==0:#入力終了
   break
  l=[]
 
  s=0
  for i in range(n):
    j=int(input()) #得点
    l.append(j)
    s+=j
  print((s-max(l)-min(l)) //(n-2))
