h,w = map(int,input().split())
a=[]
for _ in range(h):
    a.append(input())
cnt = 0
for i in range(h):
    cnt += a[i].count("#")
if cnt == h+w-1:
    print("Possible")
else:
    print("Impossible")
