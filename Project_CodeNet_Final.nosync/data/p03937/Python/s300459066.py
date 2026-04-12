h,w=map(int,input().split())
a=""
for i in range(h):a+=input()
print(["Imp","P",][a.count("#")==h+w-1]+"ossible")