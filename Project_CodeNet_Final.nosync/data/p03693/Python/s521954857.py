#coding:utf-8
n=[int(i) for i in input().split()]
n[0]=100*n[0]+10*n[1]+n[2]
if(n[0]%4==0):
  print("YES")
else:
  print("NO")