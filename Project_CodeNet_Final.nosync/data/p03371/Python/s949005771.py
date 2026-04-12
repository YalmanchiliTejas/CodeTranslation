a,b,c,x,y=map(int,input().split())
ans=0
m=min(x,y)
if a+b>=2*c: #Half and Half購入で安くなる可能性あるパターン
    # HaHをm枚買って残りHaH購入,または全部HaH購入,このいずれかしかあり得ない
    ans = min(2*c*m+a*(x-m)+b*(y-m), 2*c*max(x,y))
else:
    ans = a*x+b*y
print(ans)