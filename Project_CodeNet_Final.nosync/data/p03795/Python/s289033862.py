n=int(input())
print(n*800 -((n//15)*200))

'''
p,m=map(int,input().split())
s=bin(p)
s=s[2:]
n=len(s)


ans=pow(2,n) -1
if(m>=2):
    print(ans)
else:
    print(p)


m,n=map(int,input().split())
a=[False]*(n+1)
a[0]=True
for i in range(m):
    temp=list(map(int,input().split()))
    for kk in temp[1:]:
        a[kk]=True
ans=True
for nn in a:
    ans = nn and ans
if(ans):
    print("YES")
else:
    print("NO")



y,b,r = map(int,input().split())

if(r>b):
    if(b>y):
        print(int((3*y)+3))
    else:
        print(int(3*b))
else:
    if(b<y):
        print(int((3*y)-3))
    else:
        print()


  '''  




        