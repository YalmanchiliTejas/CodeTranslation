# coding: utf-8
# Your code here!
num = input().split()
a = (num[0])
b = (num[1])
c = (num[2])

key1= a + b + c
key2=int(key1)

if key2 % 4 ==0:
  print("YES")
else:
  print("NO")
    

