h,w=map(int,input().split())

a=[str(input()) for _ in range(h)]
ans=0
for i in range(h):
    ans+=a[i].count("#")
#print(ans)
if ans==h+w-1:
    print("Possible")
else:
    print("Impossible")