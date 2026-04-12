a = int(input())
k =[int(input()) for i in range(a)]
k.sort()
if a%2!=0:
  s1= 2*sum(k[a//2:]) - 2*sum(k[:a//2]) -k[a//2]-k[a//2+1]
  s2= 2*sum(k[a//2+1:]) - 2*sum(k[:a//2+1]) +k[a//2]+k[a//2-1]
  s = max(s1,s2)
else:
  s= 2*sum(k[a//2:]) - 2*sum(k[:a//2]) -k[a//2]+k[a//2-1]
print(s)
#print(2*sum(k[a//2+1:]) , 2*sum(k[:a//2]))