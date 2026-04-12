
N = input()
a = []
for i in input().split():
    a.append(int(i))

MOD = 1000000007
MOD2 = 2*MOD

buf_a = 0
for x in a:
    buf_a += x
    buf_a %= MOD

buf_b = 0
for x in a:
    buf_a -= x
    buf_b += buf_a * x
    buf_b %= MOD

print(buf_b)


# ans = (buf_a * buf_a) - buf_b
# if ans < 0:
#     ans += MOD2
# ans /= 2
# ans %= MOD
# print(int(ans))




# ll ans = (sum_a * sum_a) - sum_d; // MOD^2*4 ~ -MOD*2
# if (ans < 0) ans += MOD*2; // MOD^2*4 ~ 0
# dump(ans);
# ans /= 2; // MOD^2*2
# ans = fmod(ans , MOD);
# co(ans);
# return 0;