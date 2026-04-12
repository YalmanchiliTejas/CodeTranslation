def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + total_ls[n-1]:
        return f(n-1, x-1)
    else:
        return pati_ls[n-1] + 1 + f(n-1, x-2-total_ls[n-1])


n, x = map(int, input().split())

total_ls = [1]
pati_ls = [1]

for i in range(50):
    total_ls.append(3 + 2 * total_ls[-1])
    pati_ls.append(1 + 2 * pati_ls[-1])

print(f(n, x))
