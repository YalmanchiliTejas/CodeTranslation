#<100q.全探索（計算量注意）>
a, b, c, x, y = map(int,input().split())
ans1 = a * x + b * y
if x <= y:
    ans2 = c * 2 * x + b * (y - x)
    ans5 = c * 2 * y
else:
    ans2 = c * 2 * y + a * (x - y)
    ans5 = c * 2 * x
ans3 = a * x + c * 2 * y
ans4 = b * y + c * 2 * x
##print(ans1)
##print(ans2)
##print(ans3)
##print(ans4)
##print(ans5)
print(min(ans1,ans2, ans3, ans4, ans5))
