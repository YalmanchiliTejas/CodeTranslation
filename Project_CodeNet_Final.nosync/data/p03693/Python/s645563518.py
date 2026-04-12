#複数の文字を入力
r,g,b=input().split()

#3桁の数を構成
N=r+g+b

#Nを数値に変換
N=int(N)

#4の倍数であるか判定
if N%4==0:
    print("YES")
else:
    print("NO")