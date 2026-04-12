# coding: utf-8

input = input().split()
r=int(input[0])*100
g=int(input[1])*10
b=int(input[2])
rgb=r+g+b

if rgb % 4 == 0 :
    print("YES")
else:
    print("NO")

