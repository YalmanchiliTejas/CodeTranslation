a,b,c,x,y = map(int, input().split())
m = min(x,y)


# パターン1 Aを買いきってBを買う
ans1 = a*x + b*y
# パターン2 Aを買いきってABを買う
ans2 = a*x + 2*y*c
# パターン3 Bを買いきってABを買う
ans3 = b*y + 2*x*c
# パターン4 ABですべて買い切る
ans4 = max(x,y) * 2 * c
# パターン5 埋め合わせ
if x < y:
    ans5 = x * 2 * c + (y-x) * b 
else:
    ans5 = y * 2 * c + (x-y) * a

print(min(ans1,ans2,ans3,ans4,ans5))