N = int(input()) #入力する整数
A = list(map(int,input().split())) #入力する数列A
SUMA = sum(A) #数列の和
MOD = 10**9 + 7 # mod
C = [0] * (N-1) #累積和数列
for i in range(N-1): #\sum_{j = i+1}^{N}を求めて数列に代入する
  SUMA -= A[i]
  C[i] = SUMA
ans = 0 #求める答え
for i in range(N-1):
  ans += A[i]*C[i]
  ans %= MOD #その都度modで割った余りにする
print(ans) #答えを出力する