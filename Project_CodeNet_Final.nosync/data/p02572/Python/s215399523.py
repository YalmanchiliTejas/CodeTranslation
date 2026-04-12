# -*- coding: utf-8 -*-


# 整数の入力
n = int(input())
# スペース区切りの整数の入力
zzz = list(map(int, input().split()))
b=sum(zzz)**2
a=0
for i in range(n):
  # print(i)
  x=zzz[i]**2
  # print(x)
  a +=x
# print(b)
# for a in zzz:
#   print(a)

# print(b)
# print(a)

ans = (b-a)//2%(10**9+7)
print(ans)
