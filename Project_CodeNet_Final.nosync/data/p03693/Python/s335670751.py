r,g,b=map(str, input().split())
#入力は文字列

if int(r+g+b)%4==0:
#出力は整数
    print("YES")
else:
    print("NO")