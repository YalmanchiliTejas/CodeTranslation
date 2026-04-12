
n = int( input() )

H = list( map(int,input().split()) )

ans = 0
max_ = H[0]
for hi in H:
    if max_ <= hi:
        ans += 1
        max_ = hi

print(ans)
