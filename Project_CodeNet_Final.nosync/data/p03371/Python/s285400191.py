#Half and Half

#入力
A, B, C, X, Y = map(int, input().split())

#計算
Yen = []
for i in range(max(X+1,Y+1)):
	Yen.append(A*max(0,X-i) + B*max(0,Y-i) + 2*C*i)

#出力
print(min(Yen))