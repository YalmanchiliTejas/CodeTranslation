a,b,c,x,y = map(int, input().split())

# 合計料金
total = 0

# import ipdb; ipdb.set_trace()

same_amount = min(x,y)

x -= same_amount
y -= same_amount

# AB2枚とA,Bを1枚ずつどちらがお得か
if a+b > 2*c:
    # AB2枚の方がお得の時
    total += 2*c*same_amount
else:
    # A,B1枚ずつの方がお得の時
    total += (a+b)*same_amount

# 残りも全てABを買ったほうが良いか確認
if (x*a + y*b) > (2*(x+y)*c):
    total += (2*(x+y)*c)
else:
    # 残ったピザを１枚ずつ買う
    total += (x*a + y*b)

print(total)

