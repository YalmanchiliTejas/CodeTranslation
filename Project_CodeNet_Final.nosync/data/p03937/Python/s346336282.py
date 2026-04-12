h,w=map(int,input().split())
ans=0
for i in range(h):ans+=input().count(("#"))
if ans==h+w-1:print("Possible")
else:print("Impossible")