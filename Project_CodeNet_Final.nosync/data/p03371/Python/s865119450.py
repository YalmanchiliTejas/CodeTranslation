A,B,C,X,Y = map(int,input().split(" "))
P = 0
ans = 0
finans = 10 ** 9
for i in range(0,max(X,Y) * 2 + 1,2):
    ans = 0
    ans += C * i
    if X - i // 2 > 0:
        ans += A * (X - i // 2)
    if Y - i // 2 > 0:
        ans += B * (Y - i // 2)
    if ans < finans:
        finans = ans
print(finans)