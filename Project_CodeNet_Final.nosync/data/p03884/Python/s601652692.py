from math import factorial as f
k=int(input())
a="" 
for i in range(511,-1,-1):
 v=f(7+i)//f(i)//f(7)
 a="FESTIVA"+("L"*(k//v))+a
 k%=v
print(a)