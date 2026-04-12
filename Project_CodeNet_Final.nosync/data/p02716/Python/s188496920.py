n=int(input());l=list(map(int,input().split()));p=[0]*n;d=[0]*n
for i in range(n):p[i]=l[i]+p[i-2];d[i]=max(p[i-1]if i&1else d[i-1],l[i]+d[i-2])
print(d[-1])