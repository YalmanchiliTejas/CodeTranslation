a,b,c=map(int,input().split())
print('NO' if (a*100+b*10+c)%4 else 'YES')