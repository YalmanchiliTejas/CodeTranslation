# -*- coding: utf-8 -*-
# 整数の入力
N = int(input())
# スペース区切りの整数の入力
high_list = [int(e) for e in input().split()]

ans=1

for i in range(1,N,1):
  
  look_flag=0
  #print("旅館の高さ:",high_list[i]) #旅館の高さ

  for j in range(0,i,1):
    #print(high_list[j]," ",end="") #左側のどれかの旅館の高さ
    if high_list[j] > high_list[i]:
      look_flag=1
      #print("NG")
      break
  
  if look_flag != 1:
    #print("OK")
    ans=ans+1
  
print(ans)