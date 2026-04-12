a,b,c,x,y = map(int,input().split())

ans = []

#abピザの数を決め打ちする
for ab in range(max(x,y) + 1):
    ans.append(a * max((x - ab),0) + b * max((y - ab),0) + 2 * c * ab)

print(min(ans))