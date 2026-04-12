a, b, c, x, y = map(int, input().split())

#注文パターンを列挙する
#1. AとBのみを頼む
#2. CをAを満たすだけ頼んで、残りはBを買う
#3. CをBを満たすだけ頼んで、残りはAを買う
#4. Cのみを頼む <- 上記パターンに内包できそう

#Cは2の倍数ずつしか注文されない

#1
ans_1 = a*x + b*y
#2
ans_2 = c*x*2 + max(0, (y-x)*b)
#3
ans_3 = c*y*2 + max(0, (x-y)*a)
#4
ans_4 = c*max(x, y)*2

ans = min(ans_1, ans_2, ans_3, ans_4)
print(ans)