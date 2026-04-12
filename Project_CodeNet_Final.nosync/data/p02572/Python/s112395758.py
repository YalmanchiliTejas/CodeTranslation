n = input()
a_list = list(map(int, input().split()))
ruisekiwa = [0] * (len(a_list) + 1) 
for i in range(len(a_list)):
    ruisekiwa[i + 1] = ruisekiwa[i] + a_list[i]
sum_ = 0
mod = 10 ** 9 + 7
for i in range(len(a_list)):
    sum_ += ((a_list[i] % mod) * ((ruisekiwa[-1] % mod) - (ruisekiwa[i + 1] % mod))) % mod
print(sum_ % mod)