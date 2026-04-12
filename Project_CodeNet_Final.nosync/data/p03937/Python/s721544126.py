h,w = map(int,input().split())
cnt = 0
for i in range(h):
    A = list(input())
    cnt += A.count('#')
if cnt == h+w-1:
    print("Possible")
else:
    print("Impossible")