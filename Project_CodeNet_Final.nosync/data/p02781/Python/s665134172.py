n = int(input())
k = int(input())

def c(n, k):
    if n < k:
        return 0
    else:
        x = 1
        for i in range(k):
            x *= (n - i)
            x //= (i + 1)
        return x

ans = 0
for i in range(k):
    temp1 = len(str(n)) - 1
    temp2 = n // (10 ** temp1)
    check = k - i
    if check == 1:
        ans += temp2 + temp1 * 9
    else:
        ans += c(temp1, check) * (9 ** check) + (temp2 - 1) * c(temp1, check - 1) * (9 ** (check - 1))
    n %= 10 ** temp1
print(ans)