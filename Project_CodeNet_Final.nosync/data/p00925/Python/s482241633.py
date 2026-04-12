import re
class c(int):
    def __add__(self,n):
        return c(int(self)+int(n))
    def __mul__(self,n):
        return c(int(self)*int(n))

s=input()
d=int(input())
a=eval(re.sub(r'(\d+)',r'c(\1)',s))
b=int(s[0])
for i in range(1,len(s),2):
    if s[i]=='+':b+=int(s[i+1])
    else:b*=int(s[i+1])
if(a==b==d):e='U'
elif(a==d):e='M'
elif(b==d):e='L'
else:e='I'
print(e)