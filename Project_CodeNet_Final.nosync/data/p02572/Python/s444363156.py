n=int(input())
s=input()
p=list(s.split())
s1=0
s2=0
for i in range(0,n):
  s1=s1+int(p[i])
  s2=s2+(int(p[i])*int(p[i]))
k= ((s1**2)-s2)//2
k=k%1000000007
print(k)
 