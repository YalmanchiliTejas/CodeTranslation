n = int(input())
H = list(map(int, input().split()))
#1~N番目の高さを取り出すにはH[N-1]

seeable = 1 #1番めは必ずseeable
for i in range(2, n+1, 1): #2番目~N番目につき
  iseeable = 1
  for j in range(1, i, 1): #1番め~i-1番目につき
    if H[j-1] > H[i-1]: #i番目より高いなら見えない
      iseeable = 0
      break
  seeable += iseeable

print(seeable)