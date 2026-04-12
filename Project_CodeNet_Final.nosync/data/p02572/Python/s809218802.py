N = int(input())
MOD = 10**9 + 7
A_s = list(map(int, input().split()))
ruiseki = [] 
for i, A in enumerate(A_s):
    if i == 0:
        ruiseki.append(A)
        continue
    ruiseki.append(ruiseki[i-1]+A)
answer = 0
for i, r in enumerate(ruiseki):
    answer += (A_s[i] * (ruiseki[N-1]-ruiseki[i]))
    answer %= MOD
print(answer)