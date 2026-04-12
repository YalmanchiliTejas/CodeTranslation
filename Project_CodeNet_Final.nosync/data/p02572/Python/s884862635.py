n=int(input())
s=input()
m=list(s.split())
a=0
b=0
for i in range(0,n):
  a=a+int(m[i])
  b=b+(int(m[i])*int(m[i]))
l= ((a**2)-b)//2
l=l%1000000007
print(l)