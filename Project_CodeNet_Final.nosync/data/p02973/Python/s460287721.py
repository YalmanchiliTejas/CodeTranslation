n=int(input())
# 降順のリストで二分探索
# 自分より小さい数字で最も大きいものを自分でアップデート
# 該当がなければ最後に追加
d=[]
d.append(int(input()))
for i in range(n-1):
  a=int(input())
  ok=len(d)
  ng=-1
  while abs(ok-ng)>1:
    mid=abs(ok+ng)//2
    if d[mid]<a:
      ok=mid
    else:
      ng=mid
  if ok==len(d):
    d.append(a)
  else:
    d[ok]=a
print(len(d))