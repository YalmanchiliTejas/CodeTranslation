n=int(input());*a,=map(int,input().split());b=sorted(a);l,m=b[n//2-1],b[n//2]
for x in a:print([l,m][x<m])