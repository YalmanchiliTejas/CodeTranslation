n,k = map(int,input().split())
point = 0
for b in range(1,n+1):
    kaisu = n//b
    kosuu = max(0,b-k)
    point += kaisu*kosuu
    point += max(0,n%b+1-k)
if k == 0:
    point -= n
print(point)