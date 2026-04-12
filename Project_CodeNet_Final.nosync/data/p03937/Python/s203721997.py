# A - Shik and Stone

H, W = map(int, input().split())
now = 0
judge = 0

for h in range(H):
    route = input()
    w = 0
    while w<W and route[w]=='.':
        w += 1
    if w!=now:
        break
    while w<W-1 and route[w+1]=='#':
        w += 1
    now = w
    while w<W-1 and route[w+1]=='.':
        w += 1
    if w<W-1:
        break
    if h==H-1 and now==W-1:
        judge = 1

ans = ['Impossible', 'Possible']
print(ans[judge])