h,w=map(int,input().split())
a=[]
c=0
for i in range(h):
    tmp=input()
    c+=tmp.count("#")
if c==h+w-1:
    print("Possible")
else:
    print("Impossible")
        




