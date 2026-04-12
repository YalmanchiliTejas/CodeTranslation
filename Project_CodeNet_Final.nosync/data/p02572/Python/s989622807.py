N = int(input())
A = list(map(int,(input().split())))
total = 0
result = 0
MOD = pow(10,9)+7
l = []

for i in range(N):
    total += A[i]
    l.append(total)#累積和

for i,num in enumerate(l):
    temp = total-num #A[i+1]+A[i+2]+...+A[N]
    result += temp*A[i]#A[i](A[i+1]+A[i+2]+...+A[N])の総和

print(result%MOD)
