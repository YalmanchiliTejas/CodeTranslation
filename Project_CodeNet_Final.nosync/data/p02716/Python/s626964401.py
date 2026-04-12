n=int(input());l=list(map(int,input().split()));p=[0]*n;d=[0]*n
for i in range(n):p[i]=l[i]+(p[i-2]if i>1else 0)
for i in range(1,n):
  d[i]=p[i-1]if(i&1)else d[i-1]
  d[i]=max(d[i],l[i]+(d[i-2]if i>1else 0))
print(d[-1])