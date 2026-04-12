N = int(input())

ai_char = map(str, input().split(" "))
Ai = []
for i in ai_char:
    Ai.append(int(i))

mod_val = 1000000007
N1 = N-1
sum = 0

sum_tmp = 0
for j in range(0, N):
    sum_tmp += Ai[j]

for i in range(N1):
    sum_tmp -= Ai[i]
    sum += Ai[i] * sum_tmp

    if sum > mod_val:
        sum = sum % mod_val


print(int(sum))