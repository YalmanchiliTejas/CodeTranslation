A,B,C,X,Y = map(int, input().split())

## ABピザを買うパターン、買わないパターンの2パターンを計算して、小さい方を出力する

## 1.ABピザを買わないパターン
ans = A*X + B*Y

## 2.ABピザを買うバターン
## 2-1.余計なピザは買わない
if X > Y:
  _ = Y*C*2 + abs(X-Y)*A
else:
  _ = X*C*2 + abs(X-Y)*B
ans = min(ans,_)  

## 2-2.余計なピザを買う
_ = max(X,Y)*C*2
ans = min(ans,_)

## 3.answer
print(ans)