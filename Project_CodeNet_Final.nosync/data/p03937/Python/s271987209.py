h,w=map(int,input().split())
a=[input() for i in range(h)]
S=0
for i in range(h):
    S+=a[i].count("#")
print("Possible" if S==h+w-1 else "Impossible")