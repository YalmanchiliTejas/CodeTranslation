h,w=map(int,input().split())
a=[list(input()).count('#')for i in range(h)]
print(["Imp","P"][sum(a)==h+w-1]+"ossible")