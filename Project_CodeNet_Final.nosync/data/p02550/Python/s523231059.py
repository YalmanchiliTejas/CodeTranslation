N, X, M = map(int, input().split())

A_change_list = [0] * (M + 1)
check_list = [0] * (M + 1)

for i in range(1, M + 1):
    A_change_list[i] = i**2 % M

A = X
count = 0
sum_value = 0
ans = 0
for i in range(1, N + 1):
    if check_list[A] != 2:
        if check_list[A] == 1:
            count += 1
            sum_value += A
        ans += A
        check_list[A] += 1
        A = A_change_list[A]
    else:
        if A == 0:
            break
        elif A == 1:
            ans += N - i + 1
            break
        else:
            div, mod = divmod((N - i), count)
            ans += sum_value * div
            for _ in range(mod + 1):
                ans += A
                A = A_change_list[A]
            break

print(ans)
