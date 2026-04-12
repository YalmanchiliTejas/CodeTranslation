import math

num = int(input())
array_str = input().split(" ")
array = [int(n) for n in array_str]

value=0
a=0
b=0
modbase=int(7+math.pow(10,9))
for i in range(len(array)-1):
  bindex=i*(-1)-1
  b+=array[bindex]
  a=array[bindex-1]
  value+=a*b
print(value%modbase)