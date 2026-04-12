n = int(input())
a_list = input().split()

a_list_reverse = a_list[::-1]
# print(a_list_reverse)

rusekiwa = [0] * (len(a_list_reverse) - 1)
sum_v = 0
for i in range(len(a_list_reverse) - 1):
    sum_v += int(a_list_reverse[i])
    rusekiwa[i] = sum_v
# print(rusekiwa)

ans = 0
for i in range(len(a_list) - 1):
    v = int(a_list[i]) * rusekiwa[-1 - (i)]
    # print(v)
    # v = v % (10 ** 9 + 7)
    ans += v
    ans = ans % (10 ** 9 + 7)

# ans = ans % (10 ** 9 + 7)
print(ans)