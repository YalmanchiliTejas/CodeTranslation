r,g,b=map(str,input().split())
print('NO' if int(r+g+b)%4 else 'YES')