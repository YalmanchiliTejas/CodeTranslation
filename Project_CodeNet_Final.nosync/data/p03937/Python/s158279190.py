h,w=map(int,input().split())
ans=('Possible','Impossible')
c=0
for i in range(h):
    s=input()
    c+=s.count('#')
print(ans[0 if h+w-1==c else 1])