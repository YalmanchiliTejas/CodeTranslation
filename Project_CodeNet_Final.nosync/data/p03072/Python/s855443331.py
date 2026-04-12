n=input();*h,=map(int,input().split());p=h[0];c=1
for e in h[1:]:
 if e>=p:c+=1
 p=max(p,e)
print(c)