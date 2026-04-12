from sys import stdin
nii=lambda:map(int,stdin.readline().split())
lnii=lambda:list(map(int,stdin.readline().split()))

n,x,m=nii()

ans=x
x_list=[x]
zan=0
for i in range(n-1):
  a=(x**2)%m
  ans+=a
  x=a
  if x in x_list:
    inx=x_list.index(x)
    zan=(n-1)-i-1

    inx=x_list.index(x)+1
    nx_list=x_list[inx:]+[x_list[inx-1]]

    if zan<=len(nx_list):
      ans+=sum(nx_list[:zan])
    else:
      num=zan//len(nx_list)
      q=zan%len(nx_list)
      ans+=sum(nx_list)*num
      ans+=sum(nx_list[:q])
    break
  else:
    x_list.append(x)

print(ans)