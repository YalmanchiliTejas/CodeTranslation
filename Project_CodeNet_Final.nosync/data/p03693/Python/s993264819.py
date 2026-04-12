r,g,b=map(str,input().split())
ans=int(r+g+b)
print('YES' if ans%4==0 else 'NO')