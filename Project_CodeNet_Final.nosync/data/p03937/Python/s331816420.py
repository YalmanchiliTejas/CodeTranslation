h,w=map(int,input().split())
a=[input() for _ in range(h)]
if sum([i.count("#") for i in a])==w+h-1:
    print("Possible")
else:
    print("Impossible")