n=int(input());l=list(map(int,input().split()));p=[0]*n;d=[0]*n;p[0]=l[0]
for i in range(1,n):p[i]=l[i]+p[i-2];d[i]=max(p[i-1]if(i&1)else d[i-1],l[i]+d[i-2])
print(d[-1])